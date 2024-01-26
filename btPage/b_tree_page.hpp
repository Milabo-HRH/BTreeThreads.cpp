//
// Created by Ruihuan He on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_PAGE_HPP
#define BTREETHREADS_CPP_B_TREE_PAGE_HPP

#include <array>
#include "b_tree_slot.hpp"

// The first part of an index page.
// The page header contains the following fields:

class b_tree_page {
public:
    uint32_t cnt;                        // Count of keys in page
    uint32_t act;                        // Count of active keys
    uint32_t min;                        // Next key offset
    unsigned char bits : 7;              // Page size in bits
    unsigned char free : 1;              // Page is on free list
    unsigned char lvl : 6;               // Level of page
    unsigned char kill : 1;              // Page is being deleted
    unsigned char dirty : 1;             // Page has deleted keys
    std::array<uint8_t, BtId> right; // Page number to right

    // Constructor to initialize members
    b_tree_page() : cnt(0), act(0), min(0), bits(0), free(0), lvl(0), kill(0), dirty(0), right{} {}
};


#endif //BTREETHREADS_CPP_B_TREE_PAGE_HPP
