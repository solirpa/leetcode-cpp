cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp main.cpp)

add_executable(knapsack_problem ./leetcode/editor/cn/knapsack_problem.cpp leetcode/editor/cn/knapsack_problem.cpp)

add_executable(two_sum ./leetcode/editor/cn/1.two_sum.cpp)
add_executable(3sum ./leetcode/editor/cn/15.3sum.cpp)
add_executable(coin_change ./leetcode/editor/cn/322.coin_change.cpp)
add_executable(longest_increasing_subsequence ./leetcode/editor/cn/300.longest_increasing_subsequence.cpp)
add_executable(maximum_subarray ./leetcode/editor/cn/53.maximum_subarray.cpp)
add_executable(coin_change_2 ./leetcode/editor/cn/518.coin_change_2.cpp)
add_executable(partition_equal_subset_sum ./leetcode/editor/cn/416.partition_equal_subset_sum.cpp)
add_executable(edit_distance ./leetcode/editor/cn/72.edit_distance.cpp)
add_executable(super_egg_drop ./leetcode/editor/cn/887.super_egg_drop.cpp)
add_executable(burst_balloons ./leetcode/editor/cn/312.burst_balloons.cpp)
add_executable(longest_common_subsequence ./leetcode/editor/cn/1143.longest_common_subsequence.cpp)
add_executable(sliding_window_maximux ./leetcode/editor/cn/239.sliding_window_maximum.cpp)
add_executable(stone_game ./leetcode/editor/cn/877.stone_game.cpp)
add_executable(lru_cache ./leetcode/editor/cn/146.lru_cache.cpp)