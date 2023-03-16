#pragma once

class MyArray
{
public:

    MyArray();
    
    MyArray(size_t size);
    
    MyArray(int* arr,size_t size);

    int* array;
    int size;

    MyArray* operator+(const MyArray& arr) const;
    bool operator==(const MyArray& arr) const;
    bool operator!=(const MyArray& arr) const;
    bool operator>(const MyArray& arr) const;
    bool operator<(const MyArray& arr) const;

    int get(int index);
    void set(int index, int value);
};
