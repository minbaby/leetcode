cmake_minimum_required(VERSION 3.10)

project(leet-code VERSION 0.0.1)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_STANDARD 11)

#引入pkg-config
find_package(PkgConfig)

#通过pkg-config获得criterion
pkg_check_modules(UNITTEST criterion)

set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(HEADER_FILES
        src/main/2-add-two-numbers/2.h
        src/utils.h
        src/main/1-two-sum/1.h
        src/main/3-longest-substring-without-repeating-characters/3.h
        src/main/4-findMedianSortedArrays/4.h
        src/main/5-longest-palindromic-substring/5.h
        src/main/6-zigzag-conversion/6.h
        src/main/7-reverse-integer/7.h
        src/main/8-string-to-integer-atoi/8.h
        src/main/9-palindrome-number/9.h
        src/main/10-regular-expression-matching/10.h
        src/main/11-container-with-most-water/11.h
        src/main/12-integer-to-roman/12.h
        src/main/13-roman-to-integer/13.h
        src/main/14-longest-common-prefix/14.h
        )

set(SOURCE_FILES
        src/main/2-add-two-numbers/2.c
        src/utils.c
        src/main/1-two-sum/1.c
        src/main/3-longest-substring-without-repeating-characters/3.c
        src/main/4-findMedianSortedArrays/4.c
        src/main/5-longest-palindromic-substring/5.c
        src/main/6-zigzag-conversion/6.c
        src/main/7-reverse-integer/7.c
        src/main/8-string-to-integer-atoi/8.c
        src/main/9-palindrome-number/9.c
        src/main/10-regular-expression-matching/10.c
        src/main/11-container-with-most-water/11.c
        src/main/12-integer-to-roman/12.c
        src/main/13-roman-to-integer/13.c
        src/main/14-longest-common-prefix/14.c
        )

add_executable(runmain  ${HEADER_FILES} ${SOURCE_FILES} src/main/main.c)

#如果成功获取criterion说明机器是安装了criterion，可进入单测环节
if (UNITTEST_FOUND)
    #设置单元测试的源码
    set(UNITTEST_SOURCE
            src/main/1-two-sum/1_test.c
            src/main/2-add-two-numbers/2_test.c
            src/main/3-longest-substring-without-repeating-characters/3_test.c
            src/main/4-findMedianSortedArrays/4_test.c
            src/main/5-longest-palindromic-substring/5_test.c
            src/main/6-zigzag-conversion/6_test.c
            src/main/7-reverse-integer/7_test.c
            src/main/8-string-to-integer-atoi/8_test.c
            src/main/9-palindrome-number/9_test.c
            src/main/10-regular-expression-matching/10_test.c
            src/main/11-container-with-most-water/11_test.c
            src/main/12-integer-to-roman/12_test.c
            src/main/13-roman-to-integer/13_test.c
            src/main/14-longest-common-prefix/14_test.c
            )

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