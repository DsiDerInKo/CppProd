void removeFractionalPart(double* number);

void removeFractionalPart(double& number);

void switchNumSing(double* number);

void switchNumSing(double& number);

typedef struct circles {

	double xCenterCoordinate;
	double yCenterCoordinate;
	double radius;

}circle;

typedef struct mathVectors {

	double x;
	double y;

}mathVector;

void moveCircleByVector(circle* self, mathVector* vect);

void moveCircleByVector(circle& self, mathVector& vect);

typedef struct matrixs {

	int arr[3][3];

}matrix_3x3;

void multMatrixForInteger(matrix_3x3* self);

void multMatrixForInteger(matrix_3x3& self);

typedef enum funcs {
	removeFractPart1 = 11,
	removeFractPart2 = 12,
	switchNumberSing1 = 21,
	switchNumberSing2 = 22,
	moveCircle1 = 31,
	moveCircle2 = 32,
	multMatrix1 = 41,
	multMatrix2 = 42
}fun;

void tester();