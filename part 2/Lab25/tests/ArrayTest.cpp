#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.h"

TEST(ArrayTests, addTest)
{
    Array<int> array = Array<int>(10);
    int a = 5;
    array.Add(a);    
    ASSERT_EQ(array.GetSize(), 1);
}

TEST(ArrayTests, removeTest)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    auto it = array.begin();
    ++it;
    array.Remove(it);
    ASSERT_EQ(array.GetSize(), 1);
    ASSERT_EQ(array[0], a);
}

TEST(ArrayTests, updateTest)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60, c = 70;
    array.Add(a);
    array.Add(b);
    auto it = array.begin();
    it++;
    array.Update(it, c);
    ASSERT_EQ(array[1], c);
}

TEST(ArrayTests, findTest)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60, c = 70;
    array.Add(a);
    array.Add(b);
    array.Add(c);
    auto it = array.Find(b);
    ASSERT_EQ(*it, b);
}

TEST(ArrayTest, clearTest)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    array.Clear();
    ASSERT_EQ(array.GetSize(), 0);
    ASSERT_THROW(array[0], OverflowSizeExeception);  
}

TEST(ArrayTests, outputTest)
{
    Array<int> array = Array<int>();
    Array<int> array2 = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    array2.Add(b);
    array2.Add(a);
    std::ostringstream stream;
    stream << array << array2;
    std::string output = stream.rdbuf()->str();
    ASSERT_EQ(output, "48\n60\n60\n48\n");
}

TEST(ArrayTest, inputTest)
{
    Array<int> array = Array<int>(1);
    Array<int> array2 = Array<int>(1);
    std::stringstream stream;
    stream << 4 << std::endl;
    stream << "string" << std::endl;    
    stream << 5 << std::endl;
    stream >> array >> array2;
    ASSERT_EQ(array[0], 4);
    ASSERT_EQ(array2[0], 5);
}

TEST(ArrayTests, scaleTest)
{
    Array<int> array = Array<int>(1);
    int a = 4, b = 5;
    array.Add(a);
    array.Add(b);
    ASSERT_EQ(array.GetSize(), 2);
    ASSERT_EQ(array[0], 4);
    ASSERT_EQ(array[1], 5);
}

TEST(ArrayTests, indexingCorrect)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    ASSERT_EQ(a, array[0]);
    ASSERT_EQ(b, array[1]);
}

TEST(ArrayTests, indexingInCorrect)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    ASSERT_THROW(array[3], OverflowSizeExeception);
}

TEST(ArrayTests, plusCorrect)
{
    Array<int> array1 = Array<int>();
    Array<int> array2 = Array<int>();
    int a = 48, b = 60, c = 12, d = -10;
    array1.Add(a);
    array1.Add(b);
    array2.Add(c);
    array2.Add(d);
    IAddable<int>* array3 = &(array1 + array2);
    ASSERT_EQ(array3->GetSize(), 2);
    ASSERT_EQ(array3->operator[](0), a+c);
    ASSERT_EQ(array3->operator[](1), b+d);
}

TEST(ArrayTests, productCorrect)
{
    Array<int> array1 = Array<int>();
    Array<int> array2 = Array<int>();
    int a = 48, b = 60, c = 12, d = -10;
    array1.Add(a);
    array1.Add(b);
    array2.Add(c);
    array2.Add(d);
    IProductable<int>* array3 = &(array1 * array2);
    ASSERT_EQ(array3->GetSize(), 2);
    ASSERT_EQ(array3->operator[](0), a*c);
    ASSERT_EQ(array3->operator[](1), b*d);
}

class Hard
{
    public:
        Hard():Hard(4,5){}
        Hard(double A, double B){
            a = A;
            b = B;
        }        
        Hard operator+(const Hard& h2){
            return Hard(h2.a + a, h2.b + b);
        }
        Hard operator*(const Hard& h2){
            return Hard(h2.a * a, h2.b * b);
        }
    private:
        double a;
        double b;
    };

TEST(ArrayTest, hardTemplate)
{
    Array<Hard> array = Array<Hard>();
    Hard h1 = Hard(4.0, 5.0);
    array.Add(h1);
    IAddable<Hard>* summ = &(array + array);
    ASSERT_EQ(summ->GetSize(), 1);
}