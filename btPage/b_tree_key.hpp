//
// Created by Ruihuan He on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_KEY_HPP
#define BTREETHREADS_CPP_B_TREE_KEY_HPP
#include <vector>

// Key structure
class b_tree_key {
    unsigned char len;

    std::vector<unsigned char> key; // Dynamically sized key

    b_tree_key(unsigned char length) : len(length), key(length) {}
};


#endif //BTREETHREADS_CPP_B_TREE_KEY_HPP
