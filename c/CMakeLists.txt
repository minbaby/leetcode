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
        src/main/15-3sum/15.h
        src/main/16-3sum-closest/16.h
        src/main/17-letter-combinations-of-a-phone-number/17.h
        src/main/18-4sum/18.h
        src/main/19-remove-nth-node-from-end-of-list/19.h
        src/main/20-valid-parentheses/20.h
        src/main/21-merge-two-sorted-lists/21.h
        src/main/22-generate-parentheses/22.h
        src/main/23-merge-k-sorted-lists/23.h
        src/main/24-swap-nodes-in-pairs/24.h
        src/main/25-reverse-nodes-in-k-group/25.h
        src/main/26-remove-duplicates-from-sorted-array/26.h
        src/main/27-remove-element/27.h
        src/main/28-implement-strstr/28.h
        src/main/29-divide-two-integers/29.h
        src/main/31-next-permutation/31.h
        src/main/400-binary-watch/400.h
        src/main/832-flipping-an-image/832.h
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
        src/main/15-3sum/15.c
        src/main/16-3sum-closest/16.c
        src/main/17-letter-combinations-of-a-phone-number/17.c
        src/main/18-4sum/18.c
        src/main/19-remove-nth-node-from-end-of-list/19.c
        src/main/20-valid-parentheses/20.c
        src/main/21-merge-two-sorted-lists/21.c
        src/main/22-generate-parentheses/22.c
        src/main/23-merge-k-sorted-lists/23.c
        src/main/24-swap-nodes-in-pairs/24.c
        src/main/25-reverse-nodes-in-k-group/25.c
        src/main/26-remove-duplicates-from-sorted-array/26.c
        src/main/27-remove-element/27.c
        src/main/28-implement-strstr/28.c
        src/main/29-divide-two-integers/29.c
        src/main/31-next-permutation/31.c
        src/main/400-binary-watch/400.c
        src/main/832-flipping-an-image/832.c
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
            src/main/15-3sum/15_test.c
            src/main/16-3sum-closest/16_test.c
            src/main/17-letter-combinations-of-a-phone-number/17_test.c
            src/main/18-4sum/18_test.c
            src/main/19-remove-nth-node-from-end-of-list/19_test.c
            src/main/20-valid-parentheses/20_test.c
            src/main/21-merge-two-sorted-lists/21_test.c
            src/main/22-generate-parentheses/22_test.c
            src/main/23-merge-k-sorted-lists/23_test.c
            src/main/24-swap-nodes-in-pairs/24_test.c
            src/main/25-reverse-nodes-in-k-group/25_test.c
            src/main/26-remove-duplicates-from-sorted-array/26_test.c
            src/main/27-remove-element/27_test.c
            src/main/28-implement-strstr/28_test.c
            src/main/29-divide-two-integers/29_test.c
            src/main/31-next-permutation/31_test.c
            src/main/400-binary-watch/400_test.c
            src/main/832-flipping-an-image/832_test.c
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