cmake_minimum_required (VERSION 2.8.10)
project (cquic)

set (COMMON_C_FLAGS "${COMMON_C_FLAGS} -g -Wall -fpic")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_C_FLAGS} -std=gnu++11")
set (CMAKE_EXE_LINKER_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B./proto-quic/third_party/binutils/Linux_x64/Release/bin -Wl,--threads -Wl,--thread-count=4 -Wl,--icf=all -m64 -pthread -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/lib/x86_64-linux-gnu -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/lib/x86_64-linux-gnu -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/x86_64-linux-gnu -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6 -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/4.6 -L/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=/home/luocn99/work/quic/test_proto-quic/proto-quic/src/build/linux/debian_wheezy_amd64-sysroot/usr/lib -Wl,-rpath-link=. -Wl,--disable-new-dtags -Wl,-rpath-link=. -Wl,--export-dynamic")

include_directories(src src/quic src/proto_quic_tools)

link_directories(lib)


add_executable(
	cquic_server

	src/main.cc
)

target_link_libraries(cquic_server quic ssl crypto pthread)
