//
// Created by 何瑞桓 on 2024-01-24.
//

#ifndef BTREETHREADS_CPP_B_TREE_LATCH_SET_HPP
#define BTREETHREADS_CPP_B_TREE_LATCH_SET_HPP

#include "../btPage/b_tree_latch.hpp"
#include <cstdint>
//use std::atomic to store variables that are shared between threads
#include <atomic>
#include <latch>

class b_tree_latch_set {
public:

//    b_tree_latch* readwrite;   //read-write latch
//    b_tree_latch* access; //access latch/page delete
//    b_tree_latch* parent;   //adoption of foster children
//    b_tree_latch* busy; //slot is being moved between chains
    std::latch* readwrite;   //read-write latch
    std::latch* access; //access latch/page delete
    std::latch* parent;   //adoption of foster children
    std::latch* busy; //slot is being moved between chains
    std::atomic<uint16_t> pin;//pin count
    std::atomic<uint64_t> page_no;   //page number

    void unlink_latch();
};


#endif //BTREETHREADS_CPP_B_TREE_LATCH_SET_HPP
