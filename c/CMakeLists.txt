cmake_minimum_required(VERSION 3.10)

project(leet-code VERSION 0.0.1)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_STANDARD 11)

include_directories(thirdparty/uthash/include)

#引入pkg-config
find_package(PkgConfig)

#通过pkg-config获得criterion
pkg_check_modules(UNITTEST criterion)

set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

file(STRINGS cmake-var/h.txt GET_HEADER_VAR)
file(STRINGS cmake-var/c.txt GET_SOURCE_VAR)
file(STRINGS cmake-var/test.txt GET_TEST_VAR)

set(HEADER_FILES ${GET_SOURCE_VAR})

set(SOURCE_FILES ${GET_SOURCE_VAR})

add_executable(runmain ${HEADER_FILES} ${SOURCE_FILES} src/main/main.c)

#如果成功获取criterion说明机器是安装了criterion，可进入单测环节
if (UNITTEST_FOUND)
    #设置单元测试的源码
    set(UNITTEST_SOURCE ${GET_TEST_VAR})

    #打开cmake测试编译
    enable_testing()

    #打印一些信息 提示用户在make之后执行make test就是单元测试
    message("-- be ready to run test case, usage: make && make test")

    #把所有的测试源码编译成可执行文件runtest
    add_executable(runtest ${UNITTEST_SOURCE} ${HEADER_FILES} ${SOURCE_FILES})

    #执行runtest需要criterion库依赖
    target_link_libraries(runtest ${UNITTEST_LIBRARIES})

    add_test(runtest runtest)
endif (UNITTEST_FOUND)

message("trigger at # 2021/10/26 22:42:47 #")