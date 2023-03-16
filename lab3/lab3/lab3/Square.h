#pragma once
#include "mathVector.h"

class Square {

public:
    Square(Point* leftBottom, Point* rightBottom, Point* leftUp);

    Point* getDot1();
    Point* getDot2();
    Point* getDot3();
    
    void setDot1(Point* number);
    void setDot2(Point* number);
    void setDot3(Point* number);
    
    bool operator == (const Square& anotherSquare) const;
    bool operator != (const Square& anotherSquare) const;
    bool operator > (const Square& anotherSquare) const;
    bool operator < (const Square& anotherSquare) const;
    Square* operator * (const double number) const;
    Square* operator + (const mathVector& vect) const;

    
private:
    Point* dot1;
    Point* dot2;
    Point* dot3;
    double squareAmount;
};
