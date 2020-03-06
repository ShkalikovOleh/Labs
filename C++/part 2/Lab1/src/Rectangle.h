#ifndef RECTANGLE_H
#define RECTANGLE_H 

class Rectangle{
public:
    //ctors
    Rectangle();
    Rectangle(double width, double height);

    //Fields methods
    double GetHeight();
    double GetWidth();
    void SetHeight(double);
    void SetWidth(double);

    //Additional functionality
    double areaSize();
    bool isSquare();
private:
    double height;
    double width;
};

#endif