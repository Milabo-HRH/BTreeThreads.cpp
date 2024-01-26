//
// Created by 何瑞桓 on 2024-01-24.
//

#ifndef BTREETHREADS_CPP_B_TREE_PAGE_SET_HPP
#define BTREETHREADS_CPP_B_TREE_PAGE_SET_HPP

#include "../btPage/b_tree_page.hpp"
#include "b_tree_pool.hpp"
#include "b_tree_latch_set.hpp"


//  The loadpage interface object
class b_tree_page_set {
public:
    uint64_t page_no;     // current page number
    b_tree_page *page;  // current page pointer
    b_tree_pool *pool;  // current page pool
    b_tree_latch_set *latch_set;    // current page latch set
};


#endif //BTREETHREADS_CPP_B_TREE_PAGE_SET_HPP
