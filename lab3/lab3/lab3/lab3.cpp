#include "Square.h"
#include "MyArray.h"
#include "mathVector.h"
#include <iostream>

int main(int argc, char* argv[]){
    MyArray* myArray1 = new MyArray(50);
    MyArray* myArray2 = new MyArray(20);
    MyArray* myArray3;
    for(int i = 0; i < myArray1->size;i++){
        myArray1->set(i,i);
    }
    for(int i = 0; i < myArray2->size;i++){
        myArray2->set(i,i);
    }
    //myArray3 = myArray1->operator+(*myArray2);
    myArray3 = *myArray1+*myArray2;
    for (int i = 0;i<70;i++)
    {
        std::cout << myArray3->get(i) << '\n';
    }
    //myArray1->operator<(*myArray2);
    std::cout << (myArray1<myArray2)<< '\n';
    std::cout << (myArray1!=myArray2)<< '\n';
    std::cout << (myArray1>myArray2)<< '\n';
    std::cout << (myArray1==myArray2)<< '\n' << '\n';

    
    Square* square = new Square(new Point(1,1),new Point(4,1),new Point(1,4));
    mathVector* vect = new mathVector(1,2);

    //square = square->operator+(*vect);
    square = (*square)+(*vect);
    Square* newsquare = (*square)*(3);

    square->operator==(*newsquare);

    std::cout << (square<newsquare)<< '\n';
    std::cout << (square>newsquare)<< '\n';
    std::cout << (square==newsquare)<< '\n';
    std::cout << (square!=newsquare)<< '\n';
    
    return 0;
}
