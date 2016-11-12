cmake_minimum_required(VERSION 2.6)

add_executable(chap2_keyword chap2_keyword.cpp)
set_target_properties(chap2_keyword PROPERTIES COMPILE_FLAGS "-std=c++11")

add_executable(chap2_test_1 chap2_test_1.cpp)
set_target_properties(chap2_test_1 PROPERTIES COMPILE_FLAGS "-std=c++11")
