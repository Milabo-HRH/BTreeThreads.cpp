//
// Created by 何瑞桓 on 2024-01-23.
//

#ifndef BTREETHREADS_CPP_B_TREE_SLOT_HPP
#define BTREETHREADS_CPP_B_TREE_SLOT_HPP


#include <cstdint> // for uint32_t
#include <array>

constexpr size_t BtId = 6// length of id
constexpr size_t BT_maxbits = 24// maximum page size in bits
constexpr size_t BT_minbits = 9// minimum page size in bits
constexpr size_t BT_minpage = (1 << BT_minbits)// minimum page size
constexpr size_t BT_maxpage = (1 << BT_maxbits)// maximum page size


//	Page key slot definition.

//	If BT_maxbits is 15 or less, you can save 4 bytes
//	for each key stored by making the first two uint32_t
//	into uint16_t.  You can also save 4 bytes by removing
//	the tod field from the key.

//	Keys are marked dead, but remain on the page until
//	it cleanup is called. The fence key (highest key) for
//	the page is always present, even after cleanup.

class b_tree_slot{
public:
    uint32_t off : BT_maxbits; // Page offset for key start
    uint32_t dead : 1;         // Set for deleted key
    uint32_t tod;              // Time-stamp for key
    std::array<uint8_t , BtId> id; // ID associated with key
};



#endif //BTREETHREADS_CPP_B_TREE_SLOT_HPP
