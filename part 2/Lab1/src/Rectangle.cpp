#include "Rectangle.h"

Rectangle::Rectangle(){
    this->width = 10;
    this->height = 10;
}

//sizes in meters
Rectangle::Rectangle(double width, double height){
    if(width > 0 && height > 0){
        this->width = width;
        this->height = height;
    }
    else{
        this->width = 10;
        this->height = 10;
    } 
}

double Rectangle::GetHeight(){
    return height;
}

double Rectangle::GetWidth(){
    return width;
}

void Rectangle::SetHeight(double height){
    if(height > 0)
        this->height = height;
}

void Rectangle::SetWidth(double width){
    if(width > 0)
        this->width = width;    
}

double Rectangle::areaSize(){
    return height*width;
}

bool Rectangle::isSquare(){
    return height == width;
}