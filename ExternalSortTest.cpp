#include "ExternalSort.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(ExternalSort, sort) {
    ExternalSort externalSort(50000);
    std::stringstream input;
    input << "a b\n";
    input << "c d\n";
    input << "a e\n";
    std::stringstream output;
    externalSort.sort(input, output);
    std::string expected =
      "a b e\n"
      "c d\n";
    EXPECT_EQ(output.str(), expected);
}

// TODO: ADD MORE UNIT TESTS.

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
