#include <iostream>
#include <gtest/gtest.h>

using namespace std;

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST(FooTest, HandleNoneZeroInput)
{
    EXPECT_EQ(Factorial(0), 1);
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(4), 24);
    EXPECT_EQ(Factorial(5), 120);
    EXPECT_EQ(Factorial(6), 720);
    EXPECT_EQ(Factorial(7), 5040);
    EXPECT_EQ(Factorial(8), 40320);
    EXPECT_EQ(Factorial(9), 362880);
    EXPECT_EQ(Factorial(10), 3628800);
    EXPECT_EQ(Factorial(11), 39916800);
    EXPECT_EQ(Factorial(12), 479001600);
    EXPECT_EQ(Factorial(13), 1932053504);
    EXPECT_EQ(Factorial(14), 27048749056);
    EXPECT_EQ(Factorial(15), 405731235840);
    EXPECT_EQ(Factorial(16), 6491699773440);
    EXPECT_EQ(Factorial(17), 110358896148480);
    EXPECT_EQ(Factorial(18), 1986460130672640);
    EXPECT_EQ(Factorial(19), 37742742482780160);
    EXPECT_EQ(Factorial(20), 754854849655603200);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
