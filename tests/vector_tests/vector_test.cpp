#include "gtest/gtest.h"
#include "math/vector.h"

TEST(VectorTest, TestConstructors)
{
    frey::vector empty;

    frey::vector single_val(1.0);
    EXPECT_EQ(single_val, empty);

    frey::vector multi_val(1.0,1.0,1.0);
    EXPECT_EQ(multi_val, empty);
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
    EXPECT_EQ(test_vector, temp_vector);
}

TEST(VectorTest, TestOperators)
{
    frey::vector v1(1.0,1.0,1.0), v2(1.0,1.0,1.0);
    EXPECT_EQ(v1,v2);

    frey::vector add_result = v1 + v2;
    EXPECT_EQ(add_result, frey::vector(2.0,2.0,2.0));

    frey::vector negation_result = v1 + (!v2);
    EXPECT_EQ(negation_result, frey::vector(0.0,0.0,0.0));

    double dot_result = v1 * v2;
    EXPECT_EQ(dot_result, 3.0);

    frey::vector cross_result = v1^v2;
    EXPECT_EQ(cross_result, frey::vector(0.0,0.0,0.0));
}

int 
main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
