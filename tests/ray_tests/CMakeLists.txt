set(RAY_TEST_SOURCES 
    ../../src/math/ray.cpp
    ../../src/math/vector.cpp
    ray_test.cpp
)

add_executable(ray_tests ${RAY_TEST_SOURCES})
target_link_libraries(ray_tests gtest gtest_main)
