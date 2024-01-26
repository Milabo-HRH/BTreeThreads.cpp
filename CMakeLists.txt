cmake_minimum_required(VERSION 3.27)
project(BTreeThreads_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(btManager)
include_directories(btPage)

add_executable(BTreeThreads_cpp
        btManager/b_tree_latch_mgr.cpp
        btManager/b_tree_latch_mgr.hpp
        btManager/b_tree_latch_set.cpp
        btManager/b_tree_latch_set.hpp
        btManager/b_tree_manager.cpp
        btManager/b_tree_manager.hpp
        btManager/b_tree_page_set.cpp
        btManager/b_tree_page_set.hpp
        btManager/b_tree_pool.cpp
        btManager/b_tree_pool.hpp
        btPage/b_tree_entry.cpp
        btPage/b_tree_entry.hpp
        btPage/b_tree_key.cpp
        btPage/b_tree_key.hpp
        btPage/b_tree_latch.cpp
        btPage/b_tree_latch.hpp
        btPage/b_tree_page.cpp
        btPage/b_tree_page.hpp
        btPage/b_tree_slot.cpp
        btPage/b_tree_slot.hpp
        reference/threads2j.c
        b_tree.cpp
        b_tree.hpp)
find_package(TBB REQUIRED
            Boost REQUIRED)
target_link_libraries(BTreeThreads_cpp TBB::tbb boost_system boost_thread)