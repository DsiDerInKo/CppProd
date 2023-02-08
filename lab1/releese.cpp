#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <math.h>

#pragma once
#include <iostream>

void removeFractionalPart(double* number) {
	(*number) = (int)(*number);
}

void removeFractionalPart(double& number) {
	number = (int)number;
}

void switchNumSing(double* number) {
	(*number) = -(*number);
}

void switchNumSing(double& number) {
	number = -number;
}

void moveCircleByVector(circle* self, mathVector* vect) {
	self->xCenterCoordinate += vect->x;
	self->yCenterCoordinate += vect->y;
}

void moveCircleByVector(circle& self, mathVector& vect) {
	self.xCenterCoordinate += vect.x;
	self.yCenterCoordinate += vect.y;
}

void multMatrixForInteger(matrix_3x3* self,int number) {
	for (size_t i = 0; i < 3; i++){
		for (size_t j = 0; j < 3; j++) {
			self->arr[i][j] *= number;
		}
	}
}

void multMatrixForInteger(matrix_3x3& self,int number) {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			self.arr[i][j] *= number;
		}
	}
}

void tester() {
	std::cout << "Enter a comand\n";
	int control;
	double num;
	int number;
	circle* self;
	mathVector* vect;
	matrix_3x3* mat;
	scanf("%d", &control);

	switch (control){
	case removeFractPart1:
		std::cout << "Enter a double number\n";
		num;
		scanf("%lf", &num);
		removeFractionalPart(&num);
		std::cout << "Answer: " << num;
		return;
	case removeFractPart2:
		std::cout << "Enter a double number\n";
		num;
		scanf("%lf", &num);
		removeFractionalPart(num);
		std::cout << "Answer: " << num;
		return;
	case switchNumberSing1:
		std::cout << "Enter a double number\n";
		num;
		scanf("%lf", &num);
		switchNumSing(&num);
		std::cout << "Answer: " << num;
		return;
	case switchNumberSing2:
		std::cout << "Enter a double number\n";
		num;
		scanf("%lf", &num);
		switchNumSing(num);
		std::cout << "Answer: " << num;
		return;
	case moveCircle1:
		self = new circle;
		std::cout << "Enter radius, xCoordinate, yCoordinate of circle\n";
		scanf("%lf %lf %lf", &self->radius, &self->xCenterCoordinate, &self->yCenterCoordinate);
		vect = new mathVector;
		std::cout << "Enter xCoordinate, yCoordinate of vector\n";
		scanf("%lf %lf", &vect->x, &vect->y);

		moveCircleByVector(self, vect);

		std::cout << "Answer: " << self->xCenterCoordinate << " " << self->yCenterCoordinate;
		return;
	case moveCircle2:
		self = new circle;
		std::cout << "Enter radius, xCoordinate, yCoordinate of circle\n";
		scanf("%lf %lf %lf", &self->radius, &self->xCenterCoordinate, &self->yCenterCoordinate);
		vect = new mathVector;
		std::cout << "Enter xCoordinate, yCoordinate of vector\n";
		scanf("%lf %lf", &vect->x, &vect->y);

		moveCircleByVector(self, vect);

		std::cout << "Answer: " << self->xCenterCoordinate << " " << self->yCenterCoordinate;
		return;
	case multMatrix1:
		mat = new matrix_3x3;
		
		std::cout << "Enter a matrix in string\n";
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				scanf("%d ", &mat->arr[i][j]);
			}
		}
		number;
		std::cout << "Enter a number\n";
		scanf("%d", &number);
		multMatrixForInteger(mat,number);

		std::cout << "Answer:";
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				std::cout << " " << mat->arr[i][j];
			}
		}
		return;

	case multMatrix2:
		mat = new matrix_3x3;

		std::cout << "Enter a matrix in string\n";
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				scanf("%d ", &mat->arr[i][j]);
			}
		}
		number;
		std::cout << "Enter a number\n";
		scanf("%d", &number);
		multMatrixForInteger(mat, number);

		std::cout << "Answer:";
		for (size_t i = 0; i < 3; i++) {
			for (size_t j = 0; j < 3; j++) {
				std::cout << " " << mat->arr[i][j];
			}
		}
		return;
	default:
		break;
	}
}