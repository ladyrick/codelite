cmake_minimum_required(VERSION 3.8)
project(codelite)

set(CMAKE_CXX_STANDARD 11)
#SET(CMAKE_CXX_COMPILER "clang++")

# add all the files in a dir and create a target
function(add_dir_target DIR)
    aux_source_directory(${DIR} dir_${DIR})
    add_executable(tag_${DIR} ${dir_${DIR}})
endfunction()

add_dir_target(test)

#add_dir_target(ch2_1)
#add_dir_target(ch2_3)
#add_dir_target(ch3_1)
#add_dir_target(ch3_2)
#add_dir_target(ch3_4)
#add_dir_target(ch4_1)
#add_dir_target(ch4_2)
#add_dir_target(ch6_1)
#add_dir_target(ch6_2)
#add_dir_target(ch6_3)
#add_dir_target(ch6_4)
#add_dir_target(ch6_5)
#add_dir_target(ch7_1)
#add_dir_target(ch7_2)
#add_dir_target(ch7_3)
#add_dir_target(ch7_4)
#add_dir_target(ch7_5)
#add_dir_target(ch7_6)
#add_dir_target(ch7_7)
#add_dir_target(ch7_8)
#add_dir_target(ch7_9)
#add_dir_target(ch7_10)
add_dir_target(ch8_1)
add_dir_target(ch8_2)
add_dir_target(ch8_3)
add_dir_target(ch8_4)
add_dir_target(ch9)
add_dir_target(ch10)