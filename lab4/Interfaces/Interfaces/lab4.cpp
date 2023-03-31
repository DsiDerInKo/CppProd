#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Parallelogram.h"
#include <algorithm>

using namespace std;

enum commands
{
    addFigure = 1,
    showAllFigures,
    peremetersSumm,
    squareSumm,
    centreMass,
    memoryUsed,
    sortObjects,
    exitFromProgramm
};

void getMenu(){
    cout << "Menu:" << '\n' << '\n';
    cout << "1: Add figure " << '\n';
    cout << "2: Show all figures" << '\n';
    cout << "3: Sum all perimeters" << '\n';
    cout << "4: Sum all areas" << '\n';
    cout << "5: System weight center" << '\n';
    cout << "6: Show figures memory" << '\n';
    cout << "7: Sort" << '\n';
    cout << "8: Exit" << '\n';
    cout << "Add command: " << '\n';
}

void getSubMenu(){
    cout << "Which figure?" << '\n';
    cout << "1: Rectangle" << '\n';
    cout << "2: Parallelogram" << '\n';
}

void throwInvalidComand(){
    cout << "Invalid comand, try another" << '\n' << '\n';
}

void showAll(std::vector<IFigure*> list){
    for(IFigure*& figure : list){
        figure->draw();
    }
}

void showAllMass(std::vector<IFigure*> list){
    for(IFigure*& figure : list){
        cout << figure->mass() << " ";
    }
}

int main(int argc, char* argv[]){
    
    std::vector<IFigure*> list;
    int action;
    double x, y, perSum, sqSum, massAll;
    CVector2D centerMass;
    double amount=0;

    while(true) {
        getMenu();

        cin >> action;
        cout << '\n';

        switch(action) {

        case exitFromProgramm:
            return 0;
            
        case addFigure:
            getSubMenu();

            cin >> action;
            cout << '\n';

            if(action==1){
                list.push_back(new Rectangle());
            }
            else if (action == 2){
                list.push_back(new Parallelogram());
            }
            else{
                throwInvalidComand();
            }
            
            break;

        case showAllFigures:
            for(IFigure*& figure : list){
                figure->draw();
                cout << '\n';
            }
            break;
        case memoryUsed:
            amount=0;

            for(IFigure*& figure : list){
                amount+=figure->size();
            }

            cout << "Figures memory: " << amount << '\n';
            break;
        case sortObjects:
            sort(list.begin(),list.end(),[](IFigure* x, IFigure* y)
            {
                return *x < *y;
            });

            showAllMass(list);
            
            cout << '\n';
            break;
        case peremetersSumm:
            perSum=0;

            for(IFigure*& figure : list){
                perSum+=figure->perimeter();
            }

            cout << "Total peremeter is: " << perSum << '\n';
            
            break;

        case squareSumm:
            sqSum = 0;

            for(IFigure*& figure : list){
                sqSum+=figure->perimeter();
            }

            cout << "Total square is: " << sqSum << '\n';
            
            break;

        case centreMass:
            massAll=0;
            x=0;
            y=0;

            for(IFigure*& figure : list){
                massAll+=figure->mass();
                x+=figure->position().x * figure->mass();
                y+=figure->position().y * figure->mass();
            }
            
            cout << "Center of whole system is: " << "(" << x/massAll << ";" << y/massAll << ")" << '\n';
            
            break;
            
        default:
            throwInvalidComand();
            break;
        }
    }
    
    return 0;
}
