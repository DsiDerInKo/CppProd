#include "Polynom.h"
#include <vector>
#include <math.h>
#include <limits>
#include <iostream>
#include <array>
#include <optional>


Polynom::Polynom(const Polynom& other) = default;

Polynom::Polynom() {
	a = 1;
	b = 1;
	c = 1;
}

Polynom::Polynom(double aCof, double bCof, double cCof) {
	a = aCof;
	b = bCof;
	c = cCof;
}

int Polynom::getNumberOfRoots() {
	double disc = b * b - 4 * a * c;
	if (disc < 0) return 0;
	else if (disc == 0) return 1;
	else return 2;
}

std::array<double, 2> Polynom::getRoots() {
	if (getNumberOfRoots() == 0) return {NULL,NULL};

	std::array<double, 2> ans;
	
	ans[0] = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	ans[1] = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	return ans;
}

double Polynom::getMin() {
	if (a < 0) return std::numeric_limits< double >::min();
	else return (-b) / (2 * a);
}

double Polynom::getMax() {
	if (a > 0) return std::numeric_limits< double >::max();
	else return (-b) / (2 * a);
}

double Polynom::getValue(double x) {
	return a * x * x + b * x + c;
}

void Polynom::printPolynomView() {
	std::cout << a << "x^2 + " << b << "x + " << c<<'\n';
}

double Polynom::getACof() {
	return a;
}

double Polynom::getBCof() {
	return b;
}

double Polynom::getCCof() {
	return c;
}

void Polynom::setACof(double x) {
	this->a = x;
}

void Polynom::setBCof(double x) {
	this->b=x;
}

void Polynom::setCCof(double x) {
	this->c=x;
}
