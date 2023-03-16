#include "Square.h"

Square::Square(Point* leftBottom, Point* rightBottom, Point* leftUp){
    dot1 = leftBottom;
    dot2 = rightBottom;
    dot3 = leftUp;
    squareAmount = (leftUp->y-leftBottom->y)*(rightBottom->x-leftBottom->x);
}

Point* Square::getDot1(){
    return dot1;
}

Point* Square::getDot2(){
    return dot2;
}

Point* Square::getDot3(){
    return dot3;
}

void Square::setDot1(Point* number){
    dot1 = number;
}

void Square::setDot2(Point* number){
    dot2 = number;
}

void Square::setDot3(Point* number){
    dot3 = number;
}

bool Square::operator==(const Square& anotherSquare) const{
    return squareAmount == anotherSquare.squareAmount;
}

bool Square::operator!=(const Square& anotherSquare) const{
    return squareAmount != anotherSquare.squareAmount;
}

bool Square::operator>(const Square& anotherSquare) const{
    return squareAmount > anotherSquare.squareAmount;
}

bool Square::operator<(const Square& anotherSquare) const{
    return squareAmount < anotherSquare.squareAmount;
}

Square* Square::operator*(const double number) const{
    return new Square(new Point(dot1->x,dot1->y),
        new Point(dot2->x,dot2->y*number),
        new Point(dot3->x,dot3->y*number));
}

Square* Square::operator+(const mathVector& vect) const{
    return new Square(
        new Point(dot1->x+vect.self.x,dot1->y+vect.self.y),
        new Point(dot2->x+vect.self.x,dot2->y+vect.self.y),
        new Point(dot3->x+vect.self.x,dot3->y+vect.self.y)
        );
}


