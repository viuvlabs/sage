#include <gtest/gtest.h>

auto add = [](int a, int b) { return a + b; };

TEST(BASIC, add)
{
    ASSERT_EQ(add(5, 5), 10);
    ASSERT_EQ(add(-5, -5), -10);
    ASSERT_EQ(add(45, 45), 90);
};

auto sub = [](int a, int b) { return a - b; };

TEST(BASIC, sub)
{
    ASSERT_EQ(sub(5, 5), 0);
    ASSERT_EQ(sub(45, 5), 40);
    ASSERT_EQ(sub(0, 45), -45);
}