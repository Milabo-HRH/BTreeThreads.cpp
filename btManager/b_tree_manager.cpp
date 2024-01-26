//
// Created by Ruihuan He on 2024-01-23.
//

#include "b_tree_manager.hpp"

b_tree_manager::~b_tree_manager() {
    for(uint16_t slot=1; slot<poolmax; ++slot) {
        auto pool = pools + slot;
        if(pool->slot) {
            munmap(pool->map, (poolmask+1) << pagebits);
        }
    }
    //store the vector of latch sets

    munmap (latch_sets, latch_mgrs->nlatchpage * pagesize);
    munmap (latch_mgrs, pagesize);
    //todo Serialize the hashmap
}
