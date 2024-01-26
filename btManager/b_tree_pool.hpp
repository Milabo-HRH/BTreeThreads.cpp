//
// Created by 何瑞桓 on 2024-01-24.
//

#ifndef BTREETHREADS_CPP_B_TREE_POOL_HPP
#define BTREETHREADS_CPP_B_TREE_POOL_HPP

#include "../btPage/b_tree_entry.hpp"



class b_tree_pool {
public:
    uint64_t basepage;
    char *map;
    uint16_t slot;
    uint16_t pin;
    b_tree_pool *hashprev;
    b_tree_pool *hashnext;
};


#endif //BTREETHREADS_CPP_B_TREE_POOL_HPP
