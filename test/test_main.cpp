#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

int test(int n) {
    return n;
}

TEST(a, b) { // NOLINT
    EXPECT_EQ(test(1), 1);
    EXPECT_EQ(test(2), 2);
    EXPECT_EQ(test(3), 3);
}

int main(int argc, char **argv) {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v;
    copy(a, a + 10, back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
