cmake_minimum_required (VERSION 2.8.10)
project (cquic)

add_definitions(-DV8_DEPRECATION_WARNINGS -DUSE_UDEV -DUI_COMPOSITOR_IMAGE_TRANSPORT -DUSE_AURA=1 -DUSE_PANGO=1 -DUSE_CAIRO=1 -DUSE_GLIB=1 -DUSE_NSS_CERTS=1 -DUSE_X11=1 -DFULL_SAFE_BROWSING -DSAFE_BROWSING_CSD -DSAFE_BROWSING_DB_LOCAL -DCHROMIUM_BUILD -DENABLE_MEDIA_ROUTER=1 -DFIELDTRIAL_TESTING_ENABLED -DCR_CLANG_REVISION=\"296320-1\" -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -DCOMPONENT_BUILD -D_DEBUG -DDYNAMIC_ANNOTATIONS_ENABLED=1 -DWTF_USE_DYNAMIC_ANNOTATIONS=1 -D_GLIBCXX_DEBUG=1 -DGLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_2_32 -DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_26 -DGOOGLE_PROTOBUF_NO_RTTI -DGOOGLE_PROTOBUF_NO_STATIC_INITIALIZER -DHAVE_PTHREAD -DPROTOBUF_USE_DLLS -DBORINGSSL_SHARED_LIBRARY
)

set (COMMON_C_FLAGS "${COMMON_C_FLAGS} -g -Wall")
set (QUIC_C_FLAGS "-fno-strict-aliasing --param=ssp-buffer-size=4 -fstack-protector -Wno-builtin-macro-redefined -D__DATE__= -D__TIME__= -D__TIMESTAMP__= -funwind-tables -fPIC -pipe -Bsrc/proto-quic/third_party/binutils/Linux_x64/Release/bin -fcolor-diagnostics -m64 -march=x86-64 -pthread -Wall -Werror -Wextra -Wno-missing-field-initializers -Wno-unused-parameter -Wno-c++11-narrowing -Wno-covered-switch-default -Wno-deprecated-register -Wno-unneeded-internal-declaration -Wno-inconsistent-missing-override -Wno-shift-negative-value -Wno-undefined-var-template -Wno-nonportable-include-path -Wno-address-of-packed-member -Wno-block-capture-autoreleasing -Wno-unused-lambda-capture -Wno-user-defined-warnings -O0 -fno-omit-frame-pointer -g2 -gsplit-dwarf --sysroot=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/ -fvisibility=hidden -Xclang -load -Xclang ../src/proto-quic/third_party/llvm-build/Release+Asserts/lib/libFindBadConstructs.so -Xclang -add-plugin -Xclang find-bad-constructs -Xclang -plugin-arg-find-bad-constructs -Xclang check-auto-raw-pointer -Xclang -plugin-arg-find-bad-constructs -Xclang check-ipc -Wheader-hygiene -Wstring-conversion -Wtautological-overlap-compare -Wno-header-guard")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${QUIC_C_FLAGS} ${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS}  -std=gnu++11 -fvisibility-inlines-hidden -Wno-undefined-bool-conversion -Wno-tautological-undefined-compare -std=gnu++11 -fno-rtti -fno-exceptions")
set (CMAKE_EXE_LINKER_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B./proto-quic/third_party/binutils/Linux_x64/Release/bin -Wl,--threads -Wl,--thread-count=4 -Wl,--icf=all -m64 -pthread -Werror --sysroot=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/ -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/lib/x86_64-linux-gnu -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/lib/x86_64-linux-gnu -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6 -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6 -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=. -Wl,--disable-new-dtags -Wl,-rpath-link=. -Wl,--export-dynamic -L. -L../lib/")


include_directories(src/proto-quic src/proto-quic/third_party/protobuf/src/)

link_directories(lib)


set (
	SIMPLE_SERVER_SOURCE

	src/proto-quic/net/tools/quic/chlo_extractor.cc
	src/proto-quic/net/tools/quic/quic_default_packet_writer.cc
	src/proto-quic/net/tools/quic/quic_dispatcher.cc
	src/proto-quic/net/tools/quic/quic_epoll_alarm_factory.cc
	src/proto-quic/net/tools/quic/quic_epoll_connection_helper.cc
	src/proto-quic/net/tools/quic/quic_http_response_cache.cc
	src/proto-quic/net/tools/quic/quic_packet_reader.cc
	src/proto-quic/net/tools/quic/quic_packet_writer_wrapper.cc
	src/proto-quic/net/tools/quic/quic_per_connection_packet_writer.cc
	src/proto-quic/net/tools/quic/quic_server.cc
	src/proto-quic/net/tools/quic/quic_simple_crypto_server_stream_helper.cc
	src/proto-quic/net/tools/quic/quic_simple_dispatcher.cc
	src/proto-quic/net/tools/quic/quic_simple_per_connection_packet_writer.cc
	src/proto-quic/net/tools/quic/quic_simple_server_packet_writer.cc
	src/proto-quic/net/tools/quic/quic_simple_server_session.cc
	src/proto-quic/net/tools/quic/quic_simple_server_session_helper.cc
	src/proto-quic/net/tools/quic/quic_simple_server_stream.cc
	src/proto-quic/net/tools/quic/quic_spdy_client_stream.cc
	src/proto-quic/net/tools/quic/quic_spdy_server_stream_base.cc
	src/proto-quic/net/tools/quic/quic_time_wait_list_manager.cc
	src/proto-quic/net/tools/quic/stateless_rejector.cc
	src/proto-quic/net/tools/quic/platform/impl/quic_socket_utils.cc
	#src/proto-quic/net/tools/quic/synchronous_host_resolver.cc

    src/proto-quic/net/tools/quic/platform/impl/quic_epoll_clock.cc

    src/proto-quic/net/tools/epoll_server/epoll_server.cc
)

#add_executable(
#	cquic_server
#
#	src/main.cc
#)

add_executable(
	quic_simple_server

	src/proto-quic/net/tools/quic/quic_server_bin.cc
)

add_library(
	server_tool
	STATIC

    ${SIMPLE_SERVER_SOURCE}
)

target_link_libraries(quic_simple_server libserver_tool.a libnet.so libbase.so libbase_i18n.so  libicui18n.so  libicuuc.so boringssl protobuf_lite crcrypto url pthread libserver_tool.a)
target_link_libraries(quic_simple_server -ldl -lrt -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lglib-2.0 -lnss3 -lnssutil3 -lsmime3 -lplds4 -lplc4 -lnspr4)
target_link_libraries(server_tool libnet.so libbase.so libbase_i18n.so  libicui18n.so  libicuuc.so boringssl protobuf_lite crcrypto url pthread)
target_link_libraries(server_tool -ldl -lrt -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -lglib-2.0 -lnss3 -lnssutil3 -lsmime3 -lplds4 -lplc4 -lnspr4)
#target_link_libraries(quic_simple_server base net crypto boringssl pthread protobuf_lite url)

#add_subdirectory(lib/protobuf)
