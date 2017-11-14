cmake_minimum_required(VERSION 3.8)
project(codelite)

set(CMAKE_CXX_STANDARD 11)

# add all the files in a dir and create a target
function(add_dir_target DIR)
    aux_source_directory(${DIR} dir_${DIR})
    add_executable(tag_${DIR} ${dir_${DIR}})
endfunction()

add_dir_target(test)
add_dir_target(ch2_1)
add_dir_target(ch2_3)
add_dir_target(ch3_1)
add_dir_target(ch3_2)
add_dir_target(ch3_4)
add_dir_target(ch4_1)
add_dir_target(ch4_2)
