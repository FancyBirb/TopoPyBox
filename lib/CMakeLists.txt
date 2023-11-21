cmake_minimum_required(VERSION 3.5)

project(TopoPyBox)
set(CMAKE_C_STANDARD 11)

# gradient.c
add_library(gradient SHARED gradient.c)
set_target_properties(gradient PROPERTIES SUFFIX ".so")

# aspect.c
add_library(aspect SHARED aspect.c)
set_target_properties(aspect PROPERTIES SUFFIX ".so")