//
// Created by Ruihuan He on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_MANAGER_HPP
#define BTREETHREADS_CPP_B_TREE_MANAGER_HPP

#include <vector>
#include "../btPage/b_tree_latch.hpp"
#include "b_tree_latch_set.hpp"
#include "b_tree_latch_mgr.hpp"
#include "b_tree_pool.hpp"
// to use mmap and munmap
#include <sys/mman.h>


class b_tree_manager {
    uint32_t pagesize;  // page size
    uint32_t pagebits;  // page size in bits
    uint32_t seg_bits;  // segment size in bits
    uint32_t mode;      // read/write mode

    uint64_t idx;

    uint16_t poolcnt;   // highest number of pools in use
    uint16_t poolmax;   // highest number of pools allocated
    uint16_t poolmask;  // total number of pages in mmap segment - 1
    uint16_t evicted;   // last evicted hash table slot
    uint16_t hashsize;  // size of the hash table
    uint16_t *hash;     // pool index for hash entries
    b_tree_latch* latchs; // latches for pool hash slots
    b_tree_latch_mgr* latch_mgrs;    // mapped latch page from allocation page
    b_tree_latch_set* latch_sets;    // mapped latch set from latch pages
    b_tree_pool* pools;  // memory pool page segments


public:
//    b_tree_manager(uint32_t pagesize, uint32_t pagebits, uint32_t seg_bits, uint32_t mode, size_t idx,
//                   uint16_t poolcnt, uint16_t poolmax, uint16_t poolmask, uint16_t evicted, uint16_t hashsize,
//                   uint16_t *hash, b_tree_latch *latch, b_tree_latch_mgr *latch_mgr, b_tree_latch_set *latch_set,
//                   b_tree_pool *pool) : pagesize(pagesize), pagebits(pagebits), seg_bits(seg_bits), mode(mode),
//                                        idx(idx), poolcnt(poolcnt), poolmax(poolmax), poolmask(poolmask),
//                                        evicted(evicted), hashsize(hashsize), hash(hash), latch(latch),
//                                        latch_mgr(latch_mgr), latch_set(latch_set), pool(pool) {}

    ~b_tree_manager();

    // get a latch set's pointer based on the offset
    b_tree_latch_set* get_latch_set(uint16_t offset=0) {
        return latch_sets + offset;
    }

    // get a latch's manager's pointer based on the offset
    b_tree_latch_mgr *get_latch_mgr(uint16_t offset=0) {
        return latch_mgrs + offset;
    }
};


#endif //BTREETHREADS_CPP_B_TREE_MANAGER_HPP
