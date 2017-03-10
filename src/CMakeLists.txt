cmake_minimum_required (VERSION 2.8.10)
project (cquic)

set (COMMON_C_FLAGS "${COMMON_C_FLAGS} -g -Wall -fpic")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -std=gnu++11")

include_directories(src src/quic src/proto_quic_tools)

link_directories(lib)


add_executable(
	cquic_server

	src/main.cc
)

target_link_libraries(cquic_server quic ssl crypto pthread)
