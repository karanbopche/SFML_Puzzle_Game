
enable_testing()

add_executable(
    SANITY_TEST
    sanity_test.cpp
)

target_link_libraries(
    SANITY_TEST
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(SANITY_TEST)
