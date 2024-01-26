//
// Created by 何瑞桓 on 2024-01-24.
//

#ifndef BTREETHREADS_CPP_B_TREE_ENTRY_HPP
#define BTREETHREADS_CPP_B_TREE_ENTRY_HPP


#include "b_tree_latch.hpp"
#include <cstdint>
// use std::atomic<uint16_t> slot; instead of uint16_t slot;
#include <atomic>

class b_tree_entry {
public:
    b_tree_latch *latch;
    std::atomic<uint16_t> slot;
//public:

    b_tree_entry(uint16_t slot = 0, b_tree_latch *latch = nullptr) : latch(latch), slot(slot) {
        if(latch == nullptr){
            this->latch = new b_tree_latch();
        }
    }
    b_tree_entry(const b_tree_entry &other) : latch(other.latch), slot() {
        slot.store(other.slot.load());
    }
};


#endif //BTREETHREADS_CPP_B_TREE_ENTRY_HPP
