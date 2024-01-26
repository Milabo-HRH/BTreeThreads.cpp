//
// Created by Ruihuan He on 2024-01-24.
//

#ifndef BTREETHREADS_CPP_B_TREE_LATCH_MGR_HPP
#define BTREETHREADS_CPP_B_TREE_LATCH_MGR_HPP

#include "../btPage/b_tree_latch.hpp"
#include "../btPage/b_tree_page.hpp"
#include "../btPage/b_tree_entry.hpp"
#include <array>
#include <unordered_map>
#include <atomic>
//introduce tbb::concurrent_hash_map to maintain a concurrency-supporting hash table
#include "oneapi/tbb/concurrent_hash_map.h"
#include <boost/unordered/concurrent_flat_map.hpp>
#include <boost/unordered/unordered_flat_map_fwd.hpp>


class b_tree_latch_mgr {
public:
    friend class boost::serialization::access;

    b_tree_page alloc[2]; //next & free page_nos in right ptr
    b_tree_latch latch[1];         //allocation area lite latch
    std::atomic<uint16_t> latchdeploys;       //highest number of latch entries deployed
    std::atomic<uint16_t> nlatchpage;         //number of latch pages at BT_latch
    std::atomic<uint16_t> latchtotal;         //number of page latch entries
    std::atomic<uint16_t> latchvictim;        //next victim in the hash table
    boost::unordered::concurrent_flat_map<uint64_t, b_tree_entry> latchtable; //hash table

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & alloc;
        ar & latch;
        ar & latchdeploys;
        ar & nlatchpage;
        ar & latchtotal;
        ar & latchvictim;
        ar & latchtable;
    }
};



#endif //BTREETHREADS_CPP_B_TREE_LATCH_MGR_HPP
