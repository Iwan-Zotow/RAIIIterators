cmake_minimum_required(VERSION 3.14.0)
project(raiii VERSION 0.2.0)
project(raiii CXX)

include(CTest)
enable_testing()

add_executable(raiii main.cpp)
target_compile_features(raiii PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
