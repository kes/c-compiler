#include <iostream>
#include <gtest/gtest.h>
#include "../lexer/tokenizer.h"
#include "../lexer/global.h"
namespace {

    int getMeaningOfLife() {return 42;}
}

TEST(MyBigTest, TrivialEquality){
    EXPECT_EQ(getMeaningOfLife(), 42);
}

TEST(MyBigTest22, AnotherTrivialEquality){

    EXPECT_EQ(42, getMeaningOfLife()) << "Oh no an error!";
    ASSERT_FALSE (getMeaningOfLife() == 55);
}

TEST(TokenizerTest, IdentifyInt){
    std::string s = "       int main(void)";
    tokenS x = tokenizer(s);
    EXPECT_TRUE(x.returnCode == SUCCESS);
}
TEST(TokenizerTest, IdentifyMain){
    std::string s = "        main(void)";
    tokenS x = tokenizer(s);
    EXPECT_TRUE(x.returnCode == SUCCESS);
    EXPECT_TRUE(x.name == "IDENTIFIER") << "WRONG actual:" + x.name;
    EXPECT_TRUE(x.value == "main") << "WRONG actual:" + x.value;
}