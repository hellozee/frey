set(VECTOR_TEST_SOURCES 
    ../../src/math/vector.cpp
    vector_test.cpp
)

add_executable(vector_tests ${VECTOR_TEST_SOURCES})
target_link_libraries(vector_tests gtest gtest_main)
