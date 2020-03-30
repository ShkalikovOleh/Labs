#include <gtest/gtest.h>
#include <string>

#include "../src/InfixToPostfix.h"

TEST(InfixToPostfixTests, correct)
{
    std::string firstInfix = "(A-B-C)/D-E*F";
    std::string secondInfix = "[A+B]*C-(D+E)/F";
    std::string thirdInfix = "A/(B-C)+D*(E-F)";
    std::string fourthInfix = "(A*B+C)/D-F/E";

    std::string firstPostfix = "AB-C-D/EF*-";
    std::string secondPostfix = "AB+C*DE+F/-";
    std::string thirdPostfix = "ABC-/DEF-*+";
    std::string fourthPostfix = "AB*C+D/FE/-";

    ASSERT_EQ(firstPostfix, infixToPostfix(firstInfix));
    ASSERT_EQ(secondPostfix, infixToPostfix(secondInfix));
    ASSERT_EQ(thirdPostfix, infixToPostfix(thirdInfix));
    ASSERT_EQ(fourthPostfix, infixToPostfix(fourthInfix));
}

TEST(infixToPostfix, throwIfIncorrectBrackets)
{
    std::string incorrect1 = "((A-B-C)/D-E*F";
    std::string incorrect2 = "(A-B-C)/D-E*F)";
    EXPECT_ANY_THROW(infixToPostfix(incorrect1));
    EXPECT_ANY_THROW(infixToPostfix(incorrect2));
}

TEST(infixToPostfix, calculate)
{
    std::string infix = "(A+B)/B-A";        
    std::map<char, int> map;
    map.insert(std::pair('A', 12));
    map.insert(std::pair('B', 6));

    ASSERT_EQ(-9, calculate_infix(infix, map));
}