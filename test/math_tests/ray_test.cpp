#include "gtest/gtest.h"
#include "math/ray.h"
#include "math/vector.h"

TEST(RayTest, TestConstructors)
{
    frey::vector origin(0.0);
    frey::vector direction;

    frey::ray test_ray(origin, direction);
    EXPECT_EQ(test_ray.get_origin(), origin);
    EXPECT_EQ(test_ray.get_direction(), direction);
}

int 
main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
