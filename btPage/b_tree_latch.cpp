//
// Created by Ruihuan He on 2024-01-23.
//

#include "b_tree_latch.hpp"
//Use std::thread rather than pthread to finish the project

void b_tree_latch::lockRead() {
    std::unique_lock<std::mutex> lock(mutex);
    // If there is a writer, wait
    readCond.wait(lock, [this](){ return !write; });
    // Increment the number of readers
    share++;
}

void b_tree_latch::unlockRead() {
    std::unique_lock<std::mutex> lock(mutex);
    // Decrement the number of readers
    // If there are no more readers, notify a writer
    if (--share == 0) {
        writeCond.notify_one();
    }
}

void b_tree_latch::lockWrite() {
    std::unique_lock<std::mutex> lock(mutex);
    // If there is a writer or readers, wait
    writeCond.wait(lock, [this](){ return !write && share == 0; });
    // Set the write flag
    write = true;
}

void b_tree_latch::unlockWrite() {
    std::unique_lock<std::mutex> lock(mutex);
    // Clear the write flag
    write = false;
    // Notify all waiting threads
    readCond.notify_all();
    writeCond.notify_one();
}