#include "gtest/gtest.h"
#include "math/vector.h"

TEST(VectorTest, TestConstructors)
{
    frey::vector empty;
    EXPECT_EQ(empty.x, 1.0);
    EXPECT_EQ(empty.y, 1.0);
    EXPECT_EQ(empty.z, 1.0);

    frey::vector single_val(1.0);
    EXPECT_EQ(single_val.x, 1.0);
    EXPECT_EQ(single_val.y, 1.0);
    EXPECT_EQ(single_val.z, 1.0);

    frey::vector multi_val(1.0,1.0,1.0);
    EXPECT_EQ(multi_val.z, 1.0);
    EXPECT_EQ(multi_val.z, 1.0);
    EXPECT_EQ(multi_val.z, 1.0);
}

TEST(VectorTest, TestMagnitude)
{
    frey::vector test_vector(3.0,4.0,12.0);
    EXPECT_EQ(test_vector.magnitude(), 13.0);
}

TEST(VectorTest, TestNormalize)
{
    frey::vector temp_vector(1.0,0.0,0.0);
    frey::vector test_vector = temp_vector.normalize();
    EXPECT_EQ(test_vector.x, 1.0);
    EXPECT_EQ(test_vector.y, 0.0);
    EXPECT_EQ(test_vector.z, 0.0);
}

int 
main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
