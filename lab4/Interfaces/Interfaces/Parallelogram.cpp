#include "Parallelogram.h"
#include <iostream>

Parallelogram::~Parallelogram(){
    delete this;
}

Parallelogram::Parallelogram(){
    this->Parallelogram::initFromDialogue();
}

Parallelogram::Parallelogram(CVector2D lb, CVector2D lt, CVector2D rb, double w){
    leftBot=lb;
    leftTop = lt;
    rightBot = rb;
    weight=w;
}

double Parallelogram::mass() const{

    return weight;
    
}

CVector2D Parallelogram::position() const{
    
    CVector2D center;
    center.x = (leftTop.x + (rightBot.x-leftBot.x)-leftBot.x)/2;
    center.y = (leftTop.y-leftBot.y)/2;
    return center;
    
}

double Parallelogram::square(){
    return (rightBot.x - leftBot.x)*(leftTop.y-leftBot.y);
}

double Parallelogram::perimeter(){
    return (rightBot.x - leftBot.x)*2 + (leftTop.y-leftBot.y)*2;
}

bool Parallelogram::operator==(const IPhysObject& obj) const{
    return mass() == obj.mass();
}

bool Parallelogram::operator<(const IPhysObject& obj) const{
    return mass() < obj.mass();
}

void Parallelogram::draw(){
    
    std::cout << "Name: " << name << '\n'; 
    std::cout << "Size: " << size() << '\n';
    std::cout << "Weight: " << weight << '\n';
    std::cout << "Position: " << position().x << " " << position().y << '\n';
    
}

const char* Parallelogram::className(){
    return name;
}

unsigned Parallelogram::size(){
    return sizeof(*this);
}

void Parallelogram::initFromDialogue(){
    
    std::cout << "Enter 3 CVector2D (3 dots) and weight by lines";
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> leftBot.x >> leftBot.y;
    std::cin >> weight;
    
}
