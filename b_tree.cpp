//
// Created by Ruihuan He on 2024-01-23.
//

#include "b_tree.hpp"

void b_tree::link_latch(uint16_t victim, uint64_t page_no) {
    b_tree_latch_set *set = mgr->get_latch_set(victim);

    b_tree_entry entry;
    mgr->get_latch_mgr()->latchtable.insert(std::make_pair(page_no, entry));
//    a->second.slot = victim;
//    mgr->get_latch_mgr()->latchtable[page_no].slot = victim;
    set->page_no = page_no;
}

b_tree_latch_set *b_tree::pin_latch(uint16_t page_no) {
    b_tree_latch_set *set;
    b_tree_latch_mgr *latch_mgr = mgr->get_latch_mgr();
    tbb::concurrent_hash_map<uint64_t, b_tree_entry>::const_accessor a;
    //if page_no is in the hash table
    if(latch_mgr->latchtable.contains(page_no)) {
        set = mgr->get_latch_set(a->second.slot);
        set->pin++;
        return set;
    }
    else{
        int victim = latch_mgr->latchdeploys++ +1; //fetch_add(1);
        //if victim is in the range of latchtotal
        if(victim < latch_mgr->latchtotal){
            set = mgr->get_latch_set(victim);
            set->pin++;
            erase_latch(set->page_no);
            link_latch(victim, page_no);
            return set;
        //if victim is out of the range of latchtotal
        } else {
            latch_mgr->latchdeploys-- - 1; //fetch_sub(1);
            //wait for a victim
            while(1) {
                victim = latch_mgr->latchvictim++ + 1; //fetch_add(1);
                if (victim >= latch_mgr->latchtotal) {
                    latch_mgr->latchvictim-- - 1; //fetch_sub(1);
                    continue;
                }
                set = mgr->get_latch_set(victim);

                if (set->pin == 0) {
                    erase_latch(set->page_no);
                    link_latch(victim, page_no);
                    return set;
                }
                set->pin--;
            }
        }
    }
    return nullptr;
}



bool b_tree::erase_latch(uint64_t page_no) {
    return mgr->get_latch_mgr()->latchtable.erase(page_no);
}
