#include "Polynom.h"
#include <iostream>
#include <vector>

using namespace std;

class Menu {
public:
	void start() {
		int num;
		Polynom* tmp = new Polynom();
		while (true) {

			cout << '\n' << "Choose comand: (Write value 1-11)" << '\n';
			cout << "1: Create Polynom without your a,b,c" << '\n';
			cout << "2: Create Polynom with your a,b,c" << '\n';
			cout << "3: Number of roots" << '\n';
			cout << "4: Get roots" << '\n';
			cout << "5: Get max" << '\n';
			cout << "6: Get min" << '\n';
			cout << "7: Get value by X" << '\n';
			cout << "8: print Polynom" << '\n';
			cout << "9: view A cof" << '\n';
			cout << "10: view B cof" << '\n';
			cout << "11: view C cof" << '\n' << '\n';

			cin >> num;
			switch (num) {
			case 1:
				tmp->setACof(1);
				tmp->setBCof(1);
				tmp->setCCof(1);
				break;
			case 2:
				int a, b, c;
				cout << "write 3 cof in a row" << '\n';
				cin >> a >> b >> c;
				tmp->setACof(a);
				tmp->setBCof(b);
				tmp->setCCof(c);

				break;
			case 3:
				cout << tmp->getNumberOfRoots() << '\n';
				break;
			case 4:
				array<double, 2> newtmp = tmp->getRoots();
				if (newtmp[0] == NULL) cout << "No roots" << '\n';
				else if (newtmp[1] == NULL) cout << newtmp[0] << '\n';
				else cout << newtmp[0] << " and " << newtmp[1] << '\n';
				break;
			case 5:
				cout << tmp->getMax() << '\n';
				break;
			case 6:
				cout << tmp->getMin() << '\n';
				break;
			case 7:
				int value;
				cout << "write value" << '\n';
				cin >> value;
				cout << tmp->getValue(value) << '\n';
				break;
			case 8:
				tmp->printPolynomView();
				break;
			case 9:
				cout << tmp->getACof() << '\n';
				break;
			case 10:
				cout << tmp->getBCof() << '\n';
				break;
			case 11:
				cout << tmp->getCCof() << '\n';
				break;
			default:
				cout << "Invalid comand. Write value 1-11" << '\n';

				break;
			}

		}

	}

};

int main() {
	
	Menu* self = new Menu();
	self->start();

	return 0;
}