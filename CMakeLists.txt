cmake_minimum_required(VERSION 3.5)
project(vcf_sim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vcfparser.h vcfparser.cpp vcfstruct.h vcfstruct.cpp)
add_executable(vcf_sim ${SOURCE_FILES})