#pragma once
#include "Interfaces.h"

class Rectangle : public IFigure
{
public:
    ~Rectangle() override;
    Rectangle();
    Rectangle(CVector2D lb,CVector2D lt, CVector2D rb, double w);
    double mass() const override;
    CVector2D position() const override;
    bool operator==(const IPhysObject& obj) const override;
    bool operator<(const IPhysObject& obj) const override;
    void draw() override;
    const char* className() override;
    unsigned size() override;
    void initFromDialogue() override;
    double square() override;
    double perimeter() override;

    CVector2D leftBot;
    CVector2D leftTop;
    CVector2D rightBot;
    double weight = 0;
    const char* name = "Rectangle";
};
