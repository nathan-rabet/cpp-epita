cmake_minimum_required(VERSION 3.0.0)
project(cartesian_vector_param VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

add_executable(main main.cc vector.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
