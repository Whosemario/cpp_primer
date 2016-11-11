cmake_minimum_required(VERSION 2.6)

add_executable(chap16_test_1 chap16_test_1.cpp)
set_target_properties(chap16_test_1 PROPERTIES COMPILE_FLAGS "-std=c++11")

add_executable(chap16_test_2 chap16_test_2.cpp)
set_target_properties(chap16_test_2 PROPERTIES COMPILE_FLAGS "-std=c++11")

add_executable(chap16_test_forward chap16_test_forward.cpp)
set_target_properties(chap16_test_forward PROPERTIES COMPILE_FLAGS "-std=c++11")