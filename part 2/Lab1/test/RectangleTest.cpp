#include <gtest/gtest.h>
#include "../src/Rectangle.h"

TEST(RectangleTest, createRectAsObjectWithArgs){
    Rectangle rect = Rectangle(15, 15);
    ASSERT_DOUBLE_EQ(rect.GetWidth(), 15);
    ASSERT_DOUBLE_EQ(rect.GetHeight(), 15);
}

TEST(RectangleTest, createRectAsPointerWithArgs){
    Rectangle* rect = new Rectangle(15, 15);
    ASSERT_TRUE(rect);
    ASSERT_DOUBLE_EQ(rect->GetWidth(), 15);
    ASSERT_DOUBLE_EQ(rect->GetHeight(), 15);
}

TEST(RectangleTest, createRectAsObjectWithoutArgs){
    Rectangle rect = Rectangle(); 
    ASSERT_DOUBLE_EQ(rect.GetWidth(), 10);
    ASSERT_DOUBLE_EQ(rect.GetHeight(), 10);
}

TEST(RectangleTest, createRectAsPointerWithoutArgs){
    Rectangle* rect = new Rectangle();
    ASSERT_TRUE(rect);
    ASSERT_DOUBLE_EQ(rect->GetWidth(), 10);
    ASSERT_DOUBLE_EQ(rect->GetHeight(), 10);
}

TEST(RectangleTest, getWidhtAsObject){
    Rectangle rect = Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect.GetWidth(), 18);
}

TEST(RectangleTest, getWidhtAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect->GetWidth(), 18);
}

TEST(RectangleTest, getHeightAsObject){
    Rectangle rect = Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect.GetHeight(), 20);
}

TEST(RectangleTest, getHeightAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect->GetHeight(), 20);
}

TEST(RectangleTest, setCorrectWidthAsObject){
    Rectangle rect = Rectangle(18, 20);
    rect.SetWidth(30);
    ASSERT_DOUBLE_EQ(rect.GetWidth(), 30);
}

TEST(RectangleTest, setCorrectWidthAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    rect->SetWidth(30);
    ASSERT_DOUBLE_EQ(rect->GetWidth(), 30);
}

TEST(RectangleTest, setInCorrectWidthAsObject){
    Rectangle rect = Rectangle(18, 20);
    rect.SetWidth(-4);
    ASSERT_DOUBLE_EQ(rect.GetWidth(), 18);
}

TEST(RectangleTest, setInCorrectWidthAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    rect->SetWidth(-4);
    ASSERT_DOUBLE_EQ(rect->GetWidth(), 18);
}

TEST(RectangleTest, setCorrectHeightAsObject){
    Rectangle rect = Rectangle(18, 20);
    rect.SetHeight(30);
    ASSERT_DOUBLE_EQ(rect.GetHeight(), 30);
}

TEST(RectangleTest, setCorrectHeightAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    rect->SetHeight(30);
    ASSERT_DOUBLE_EQ(rect->GetHeight(), 30);
}

TEST(RectangleTest, setInCorrectHeightAsObject){
    Rectangle rect = Rectangle(18, 20);
    rect.SetHeight(-4);
    ASSERT_DOUBLE_EQ(rect.GetHeight(), 20);
}

TEST(RectangleTest, setInCorrectHeightAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    rect->SetHeight(-4);
    ASSERT_DOUBLE_EQ(rect->GetHeight(), 20);
}

TEST(RectangleTest, areaSizeStandartRectAsObject){
    Rectangle rect = Rectangle();
    ASSERT_DOUBLE_EQ(rect.areaSize(), 100);
}

TEST(RectangleTest, areaSizeStandartRectAsPointer){
    Rectangle* rect = new Rectangle();
    ASSERT_DOUBLE_EQ(rect->areaSize(), 100);
}

TEST(RectangleTest, areaSizeCustomRectAsObject){
    Rectangle rect = Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect.areaSize(), 18*20);
}

TEST(RectangleTest, areaSizeCustomRectAsPointer){
    Rectangle* rect = new Rectangle(18, 20);
    ASSERT_DOUBLE_EQ(rect->areaSize(), 18*20);
}

TEST(RectangleTest, isSquareStandartRectAsObject){
    Rectangle rect = Rectangle();
    ASSERT_TRUE(rect.isSquare());
}

TEST(RectangleTest, isSquareStandartRectAsPointer){
    Rectangle* rect = new Rectangle();
    ASSERT_TRUE(rect->isSquare());
}

TEST(RectangleTest, isSquareCustomAsObject){
    Rectangle rect = Rectangle();
    rect.SetHeight(4);
    rect.SetWidth(4);
    ASSERT_TRUE(rect.isSquare());
}

TEST(RectangleTest, isSquareCustomAsPointer){
    Rectangle* rect = new Rectangle();
    rect->SetHeight(4);
    rect->SetWidth(4);
    ASSERT_TRUE(rect->isSquare());
}

TEST(RectangleTest, isNotSquareCustomAsObjectIncorrectWidth){
    Rectangle rect = Rectangle();    
    rect.SetWidth(4);
    ASSERT_FALSE(rect.isSquare());
}

TEST(RectangleTest, isNotSquareCustomAsPointerIncorrectWidth){
    Rectangle* rect = new Rectangle();
    rect->SetWidth(4);
    ASSERT_FALSE(rect->isSquare());
}

TEST(RectangleTest, isNotSquareCustomAsObjectIncorrectHeight){
    Rectangle rect = Rectangle();    
    rect.SetHeight(4);
    ASSERT_FALSE(rect.isSquare());
}

TEST(RectangleTest, isNotSquareCustomAsPointerIncorrectHeight){
    Rectangle* rect = new Rectangle();
    rect->SetHeight(4);
    ASSERT_FALSE(rect->isSquare());
}