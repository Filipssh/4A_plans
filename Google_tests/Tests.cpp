#include "gtest/gtest.h"
#include "plans.h"

TEST(ResponseCodeTestSuite, Success){
    int e = Plans::parsefile("tests/test10.in");
    EXPECT_EQ(e,0);
}
TEST(ResponseCodeTestSuite, NoFile){
    int e = Plans::parsefile("tests/test20.in");
    EXPECT_EQ(e,4);
}
TEST(ResponseCodeTestSuite, NotEnoughVertices){
    int e = Plans::parsefile("tests/test30.in");
    int f = Plans::parsefile("tests/test31.in");
    EXPECT_EQ(e,1);
    EXPECT_EQ(f,1);
}
TEST(ResponseCodeTestSuite, DuplicateVertices){
    int e = Plans::parsefile("tests/test40.in");
    EXPECT_EQ(e,2);
}
TEST(ResponseCodeTestSuite, LinesCrossing){
    int e = Plans::parsefile("tests/test50.in");
    int f = Plans::parsefile("tests/test51.in");
    int g = Plans::parsefile("tests/test52.in");
    EXPECT_EQ(e,3);
    EXPECT_EQ(f,3);
    EXPECT_EQ(g,3);
}
TEST(ResponseCodeTestSuite, LinesOverlapping){
    int e = Plans::parsefile("tests/test60.in");
    EXPECT_EQ(e,5);
}
