cmake_minimum_required(VERSION 3.20)

project("spi_master_proj" C CXX ASM)

include(cmake/st-project.cmake)

add_executable(${PROJECT_NAME})
add_st_target_properties(${PROJECT_NAME})