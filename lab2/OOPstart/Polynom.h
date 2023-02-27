#pragma once

#include <array>
#include <optional>

class Polynom {
	private:
		double a, b, c;
public:
	Polynom(const Polynom& other);

	Polynom();

	Polynom(double aCof, double bCof, double cCof);

	int getNumberOfRoots();

	std::optional<std::array<double, 2>> getRoots();

	double getMin();

	double getMax();

	double getValue(double x);

	void printPolynomView();

	double getACof();

	double getBCof();

	double getCCof();
};
