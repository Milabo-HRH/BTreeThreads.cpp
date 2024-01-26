//
// Created by Ruihuan He on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_LATCH_HPP
#define BTREETHREADS_CPP_B_TREE_LATCH_HPP

// I used stl mutex to implement the latch
#include <mutex>
#include <condition_variable>

constexpr size_t BT_latchtable = 128      // number of latch manager slots

class b_tree_latch {
public:
    b_tree_latch() : share(0) {}

    // Functions to lock and unlock the latch
    void lockRead();
    void unlockRead();
    void lockWrite();
    void unlockWrite();

private:
    std::mutex mutex;                     // Mutex for protecting access
    std::condition_variable readCond;     // Condition variable for readers
    std::condition_variable writeCond;    // Condition variable for writers
    uint16_t share;                 // Count of readers holding locks
    bool write = false;                   // Flag for write access
//    std::shared_mutex mutex;                     // Mutex for protecting access

};


#endif //BTREETHREADS_CPP_B_TREE_LATCH_HPP
