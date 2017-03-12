cmake_minimum_required (VERSION 2.8.10)
project (cquic)

set (COMMON_C_FLAGS "${COMMON_C_FLAGS} -g -Wall -fpic")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -std=gnu++11")

include_directories(src src/proto-quic src/proto_quic_tool src/proto-quic/third_party/protobuf/src/)

link_directories(lib)


set (
	SIMPLE_SERVER_SOURCE

	src/proto_quic_tool/net/tools/quic/chlo_extractor.cc
	src/proto_quic_tool/net/tools/quic/quic_default_packet_writer.cc
	src/proto_quic_tool/net/tools/quic/quic_dispatcher.cc
	src/proto_quic_tool/net/tools/quic/quic_epoll_alarm_factory.cc
	src/proto_quic_tool/net/tools/quic/quic_epoll_connection_helper.cc
	src/proto_quic_tool/net/tools/quic/quic_http_response_cache.cc
	src/proto_quic_tool/net/tools/quic/quic_packet_reader.cc
	src/proto_quic_tool/net/tools/quic/quic_packet_writer_wrapper.cc
	src/proto_quic_tool/net/tools/quic/quic_per_connection_packet_writer.cc
	src/proto_quic_tool/net/tools/quic/quic_server.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_crypto_server_stream_helper.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_dispatcher.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_per_connection_packet_writer.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_server_packet_writer.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_server_session.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_server_session_helper.cc
	src/proto_quic_tool/net/tools/quic/quic_simple_server_stream.cc
	src/proto_quic_tool/net/tools/quic/quic_spdy_client_stream.cc
	src/proto_quic_tool/net/tools/quic/quic_spdy_server_stream_base.cc
	src/proto_quic_tool/net/tools/quic/quic_time_wait_list_manager.cc
	src/proto_quic_tool/net/tools/quic/stateless_rejector.cc
	#src/proto_quic_tool/net/tools/quic/synchronous_host_resolver.cc

    src/proto_quic_tool/net/tools/quic/platform/impl/quic_epoll_clock.cc

	src/proto-quic-modify/proof_source_goquic.cc
    src/proto_quic_tool/epoll_server/epoll_server.cc
)
add_executable(
	cquic_server

	src/main.cc
)

add_executable(
	quic_simple_server

	src/proto_quic_tool/net/tools/quic/quic_server_bin.cc
    ${SIMPLE_SERVER_SOURCE}
)

target_link_libraries(cquic_server quic ssl crypto pthread)
target_link_libraries(quic_simple_server base net crypto pthread protobuf_lite url)
#target_link_libraries(quic_simple_server quic ssl crypto pthread protobuf)

add_subdirectory(lib/protobuf)
