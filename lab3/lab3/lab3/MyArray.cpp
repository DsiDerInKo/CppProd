#include "MyArray.h"

#include <vcruntime.h>

MyArray::MyArray(){
    array = new int[100];
    size = 100;
}

MyArray::MyArray(size_t sizet){
    array = new int[sizet];
    size = sizet;
}

MyArray::MyArray(int* arr,size_t sizet){
    array = new int[sizet];
    size = sizet;
    for(int i = 0;i<sizet;i++){
        array[i]=arr[i];
    }
}

int MyArray::get(int index){
    return array[index];
}

void MyArray::set(int index,int value){
    array[index]=value;
}


MyArray* MyArray::operator+(const MyArray& arr) const{
    if(size+arr.size>100) return NULL;
    int* newarr = new int[size+arr.size];
    int i=0;
    for(;i<size;i++){
        newarr[i]=array[i];
    }
    for(int j = 0;j<arr.size;j++){
        newarr[j+i] = arr.array[j];
    }
    return new MyArray(newarr,size+arr.size);
}

bool MyArray::operator==(const MyArray& arr) const{
    return arr.size==size;
}

bool MyArray::operator!=(const MyArray& arr) const{
    return arr.size!=size;
}

bool MyArray::operator>(const MyArray& arr) const{
    return arr.size>size;
}

bool MyArray::operator<(const MyArray& arr) const{
    return arr.size<size;
}


