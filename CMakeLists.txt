cmake_minimum_required (VERSION 2.8.10)

project(cquic)

set(COMMON_C_FLAGS "${COMMON_C_FLAGS} -Wall -fpic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")


