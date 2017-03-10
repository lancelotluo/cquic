cmake_minimum_required (VERSION 2.8.10)
project (cquic)

set (COMMON_C_FLAGS "${COMMON_C_FLAGS} -g -Wall -fpic")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -std=gnu++11")

include_directories(src src/proto-quic src/proto_quic_tool)

link_directories(lib)


set (
	SIMPLE_SERVER_SOURCE

	proto_quic_tool/chlo_extractor.cc
	proto_quic_tool/chlo_extractor_test.cc
	proto_quic_tool/crypto_message_printer_bin.cc
	proto_quic_tool/end_to_end_test.cc
	proto_quic_tool/quic_client_base.cc
	proto_quic_tool/quic_client_bin.cc
	proto_quic_tool/quic_client.cc
	proto_quic_tool/quic_client_session.cc
	proto_quic_tool/quic_client_session_test.cc
	proto_quic_tool/quic_client_test.cc
	proto_quic_tool/quic_default_packet_writer.cc
	proto_quic_tool/quic_dispatcher.cc
	proto_quic_tool/quic_dispatcher_test.cc
	proto_quic_tool/quic_epoll_alarm_factory.cc
	proto_quic_tool/quic_epoll_alarm_factory_test.cc
	proto_quic_tool/quic_epoll_connection_helper.cc
	proto_quic_tool/quic_epoll_connection_helper_test.cc
	proto_quic_tool/quic_http_response_cache.cc
	proto_quic_tool/quic_http_response_cache_test.cc
	proto_quic_tool/quic_packet_printer_bin.cc
	proto_quic_tool/quic_packet_reader.cc
	proto_quic_tool/quic_packet_writer_wrapper.cc
	proto_quic_tool/quic_per_connection_packet_writer.cc
	proto_quic_tool/quic_reject_reason_decoder_bin.cc
	proto_quic_tool/quic_server_bin.cc
	proto_quic_tool/quic_server.cc
	proto_quic_tool/quic_server_test.cc
	proto_quic_tool/quic_simple_crypto_server_stream_helper.cc
	proto_quic_tool/quic_simple_dispatcher.cc
	proto_quic_tool/quic_simple_per_connection_packet_writer.cc
	proto_quic_tool/quic_simple_server_bin.cc
	proto_quic_tool/quic_simple_server.cc
	proto_quic_tool/quic_simple_server_packet_writer.cc
	proto_quic_tool/quic_simple_server_session.cc
	proto_quic_tool/quic_simple_server_session_helper.cc
	proto_quic_tool/quic_simple_server_session_helper_test.cc
	proto_quic_tool/quic_simple_server_session_test.cc
	proto_quic_tool/quic_simple_server_stream.cc
	proto_quic_tool/quic_simple_server_stream_test.cc
	proto_quic_tool/quic_simple_server_test.cc
	proto_quic_tool/quic_spdy_client_stream.cc
	proto_quic_tool/quic_spdy_client_stream_test.cc
	proto_quic_tool/quic_spdy_server_stream_base.cc
	proto_quic_tool/quic_spdy_server_stream_base_test.cc
	proto_quic_tool/quic_time_wait_list_manager.cc
	proto_quic_tool/quic_time_wait_list_manager_test.cc
	proto_quic_tool/stateless_rejector.cc
	proto_quic_tool/stateless_rejector_test.cc
	proto_quic_tool/synchronous_host_resolver.cc
	proto-quic-modify/proof_source_goquic.cc
	limited_mtu_test_writer.cc
	mock_epoll_server.cc
	mock_quic_session_visitor.cc
	mock_quic_time_wait_list_manager.cc
	packet_dropping_test_writer.cc
	packet_reordering_writer.cc
	quic_client_peer.cc
	quic_dispatcher_peer.cc
	quic_server_peer.cc
	quic_test_client.cc
	quic_test_server.cc
	run_all_unittests.cc
	server_thread.cc
)
add_executable(
	cquic_server

	src/main.cc
)

add_executable(
	quic_simple_server

	src/proto_quic_tool/net/tools/quic/quic_server_bin.cc
)

target_link_libraries(cquic_server quic ssl crypto pthread)
target_link_libraries(quic_simple_server quic ssl crypto pthread)

add_subdirectory(lib/protobuf)
