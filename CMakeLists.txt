cmake_minimum_required(VERSION 3.20)
project(clearn C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(shell-sort)
add_subdirectory(callonce)
add_subdirectory(main)
add_subdirectory(mthrs)
add_subdirectory(datarace)
add_subdirectory(racecondition)
add_subdirectory(instruction)
add_subdirectory(mtxlock)
add_subdirectory(condcoop)
