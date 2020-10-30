cmake_minimum_required(VERSION "3.7")

project("clhelper")

# include OpenCL
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

add_library(${PROJECT_NAME} STATIC
  src/clhelper.cpp
)
