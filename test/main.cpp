#include <iostream>
#include <string>
#include <gtest/gtest.h>

using namespace std;

unsigned long long Factorial(unsigned int number) {
    if (number <= 1) {
        return 1;
    }
    if (number > 20) {
        throw ("input number must be less than 21.");
    }
    return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST(FooTest, HandleNoneZeroInput) {
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
    EXPECT_EQ(Factorial(13), 6227020800);
    EXPECT_EQ(Factorial(14), 87178291200);
    EXPECT_EQ(Factorial(15), 1307674368000);
    EXPECT_EQ(Factorial(16), 20922789888000);
    EXPECT_EQ(Factorial(17), 355687428096000);
    EXPECT_EQ(Factorial(18), 6402373705728000);
    EXPECT_EQ(Factorial(19), 121645100408832000);
    EXPECT_EQ(Factorial(20), 2432902008176640000);
    EXPECT_THROW(Factorial(21), string);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
