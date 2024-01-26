//
// Created by 何瑞桓 on 2024-01-24.
//

#include "b_tree_latch_set.hpp"

void b_tree_latch_set::unlink_latch() {
    //pin.fetch_sub(1);
    --pin;
}