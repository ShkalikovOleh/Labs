#include <gtest/gtest.h>

#include "../src/Tasks.h"


TEST(RWTest, loadWriteTest)
{
    std::stringstream in("Lorem ipsum dolor sit amet,\n consectetur adipiscing elit, \n sed do      eiusmod tempor incididunt ut labore et dolore;magna aliqua.");
    std::stringstream out;

    std::string correct = "Lorem ipsum dolor sit amet, \nconsectetur adipiscing elit, \nsed do eiusmod tempor incididunt ut labore et dolore; magna aliqua. "; 
    
    Text temp;
    Load(in, temp);        
    Write(out, temp);
    ASSERT_EQ(correct, out.str());
}

TEST(TasksTest, Task1Test)
{
    Text text = { Array<char>{ 'W', 'o', 'r', 'l', 'd' }, Array<char>{'H', 'e', 'l', 'l', 'o'}, Array<char>{ 'W', 'o', 'r', 'l', 'd' } , Array<char> { 'a', 'b' } };

    std::stringstream out;

    Task1(out, text);   

    ASSERT_EQ("orl\nell\norl\n" ,out.str());
}

TEST(TasksTest, Task2Test)
{
    Text text = { Array<char>{ 'W', 'o', 'r', 'l', 'd' }, Array<char>{'H', 'e', 'l', 'l', 'o'}, Array<char>{ 'W', 'o', 'r', 'l', 'd' } , Array<char> { 'a', 'b' } };

    std::stringstream out;

    Task2(out, text);

    ASSERT_EQ("b.\n" ,out.str());
}

TEST(TasksTest, Task3Test)
{
    Text text = { Array<char>{ 'W', 'o', 'r', 'l', 'd' }, Array<char>{'H', 'e', 'l', 'l', 'o'}, Array<char>{ 'W', 'o', 'r', 'l', 'd' } , Array<char> { 'a', 'b' } };

    std::stringstream out;

    Task3(out, text);

    ASSERT_EQ("Hell\nb\n" ,out.str());
}

TEST(TasksTest, Task4Test)
{
    Text text = { Array<char>{ 'W', 'o', 'r', 'l', 'd' }, Array<char>{'H', 'e', 'l', 'l', 'o'}, Array<char>{ 'W', 'o', 'r', 'l', 'd' } , Array<char> { 'a', 'b' } };

    std::stringstream out;

    Task4(out, text);

    ASSERT_EQ("Hell\naab\n" ,out.str());
}

TEST(TasksTest, CountTest)
{    
    Text text = { Array<char>{ 'W', 'o', 'r', 'l', 'd' }, Array<char>{'H', 'e', 'l', 'l', 'o'}, Array<char>{ 'W', 'o', 'r', 'l', 'd' } , Array<char> { 'a', 'b' } };
    int actual = countChar(text, 'l');
    ASSERT_EQ(4, actual);
}