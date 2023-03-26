#pragma once

class IGeoFig {
public:
    virtual ~IGeoFig() = default;
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x;
    double y;
    CVector2D();
};

class IPhysObject {
public:
    virtual ~IPhysObject() = default;
    virtual double mass() const = 0;
    virtual CVector2D position() const = 0;
    virtual bool operator==(const IPhysObject& obj) const = 0;
    virtual bool operator<(const IPhysObject& obj) const = 0;
	
};

class IPrintable
{
public:
    virtual ~IPrintable() = default;
    virtual void draw() = 0;
};

class IDialogueInitiable
{
public:
    virtual ~IDialogueInitiable() = default;
    virtual void initFromDialogue() = 0;
};

class BaseCObject
{
public:
    virtual ~BaseCObject() = default;
    virtual const char* className() = 0;
    virtual unsigned int size() = 0;
};

class IFigure : public IGeoFig, public IPhysObject, public IPrintable, public IDialogueInitiable, public BaseCObject, public CVector2D
{
	
};