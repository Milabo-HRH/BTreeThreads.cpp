//
// Created by Ruihuan He on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_HPP
#define BTREETHREADS_CPP_B_TREE_HPP

#include "btManager/b_tree_manager.hpp"
#include "btManager/b_tree_latch_set.hpp"
#include "btPage/b_tree_page.hpp"


class b_tree {
    b_tree_manager *mgr;        // buffer manager for thread
    b_tree_page *cursor;        // cached frame for start/next (never mapped)
    b_tree_page *frame;         // spare frame for the page split (never mapped)
    b_tree_page *zero;          // page of zeroes to extend the file (never mapped)
    uint64_t cursor_page;         // current cursor page number
    uint8_t *mem;               // frame, cursor, page memory buffer
    int32_t found;              // last delete or insert was found
    int err;                    // last error

    // BTree constructor
    b_tree(b_tree_manager *mgr, b_tree_page *cursor, b_tree_page *frame, b_tree_page *zero, size_t cursor_page,
          uint8_t *mem, int32_t found, int err) : mgr(mgr), cursor(cursor), frame(frame), zero(zero),
                                                  cursor_page(cursor_page), mem(mem), found(found), err(err) {}

    // BTree destructor
    ~b_tree() {
        //todo: Not sure if needed to store caches on disk
        delete mgr;
        delete cursor;
        delete frame;
        delete zero;
        delete mem;
    }

    //link latch table entry into latch hash table
    void link_latch(uint16_t victim, uint64_t page_no);

    bool erase_latch(uint64_t page_no);

    //	find existing latchset or inspire new one
    //	return with latchset pinned
    b_tree_latch_set* pin_latch(uint16_t page_no);
};


#endif //BTREETHREADS_CPP_B_TREE_HPP
