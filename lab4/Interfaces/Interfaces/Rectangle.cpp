#include "Rectangle.h"
#include <iostream>

Rectangle::~Rectangle(){
    delete this;
}

Rectangle::Rectangle(){
    this->Rectangle::initFromDialogue();
}

Rectangle::Rectangle(CVector2D lb, CVector2D lt, CVector2D rb,double w){
    leftBot=lb;
    leftTop = lt;
    rightBot = rb;
    weight=w;
}

double Rectangle::mass() const{
    
    return weight;
    
}

CVector2D Rectangle::position() const{
    
    CVector2D center;
    center.x = (rightBot.x - leftBot.x ) / 2;
    center.y = (leftTop.y - leftBot.y) / 2;
    return center;
    
}

double Rectangle::square(){
    return abs((rightBot.x - leftBot.x))*abs((leftTop.y-leftBot.y));
}

double Rectangle::perimeter(){
    return abs((rightBot.x - leftBot.x))*2 + abs((leftTop.y-leftBot.y))*2;
}

bool Rectangle::operator==(const IPhysObject& obj) const{
    return mass() == obj.mass();
}

bool Rectangle::operator<(const IPhysObject& obj) const{
    return mass() < obj.mass();
}

void Rectangle::draw() {
    
    std::cout << "Name: " << name << '\n'; 
    std::cout << "Size: " << size()<< '\n';
    std::cout << "Weight: " << weight<< '\n';
    std::cout << "Position: " << position().x << " " << position().y<< '\n';
    
}

const char* Rectangle::className(){
    return name;
}

unsigned Rectangle::size(){
    return sizeof(*this);
}

void Rectangle::initFromDialogue(){

    std::cout << "Enter 3 CVector2D (3 dots) and weight by lines" << '\n';
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> weight;
}
