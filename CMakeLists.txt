cmake_minimum_required(VERSION 3.1)
project(vcf_sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES main.cpp vcfparser.h vcfparser.cpp)
add_executable(vcf_sim ${SOURCE_FILES})
