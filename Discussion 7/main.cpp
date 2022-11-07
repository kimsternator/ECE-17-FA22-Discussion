#include <iostream>
#include <map>
#include <functional>

using namespace std;

#include "Matrix.hpp"

void transposeExample();
void multiplyExample();
void determinantExample();
void tocsvExample();
void fromcsvExample();

static map<string, function<void()>> argumentFunctions = {
		{"transpose", transposeExample},
		{"multiply", multiplyExample},
		{"determinant", determinantExample},
		{"tocsv", tocsvExample},
		{"fromcsv", fromcsvExample},
};

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		return 0;
	}

	Matrix theMatrix({{1.0, 2.0, 3.0},
							{4.0, 5.0, 6.0},
							{7.0, 8.0, 9.0},
							{10.0, 11.0, 12.0}});
	argumentFunctions[argv[1]]();
	return 0;
}

void transposeExample() {
	Matrix theMatrix({{1.0, 2.0},
							  {3.0, 4.0},
							  {5.0, 6.0},
							  {7.0, 8.0}});
	cout << theMatrix << endl;
	cout << theMatrix.transpose() << endl;
}

void multiplyExample() {
	Matrix theMatrix({{1.0, 2.0},
							  {3.0, 4.0},
							  {5.0, 6.0}});
	cout << theMatrix << endl;
	cout << theMatrix.multiply(theMatrix) << endl;
}

void determinantExample() {
	Matrix theMatrix({{1.0, 2.0},
					 		{3.0, 4.0}});
//	Matrix theMatrix({{1.0, 2.0, 3.0},
//					  		{4.0, 5.0, 6.0},
//					  		{7.0, 8.0, 9.0}});
//	Matrix theMatrix({{1.0, 2.0, 3.0},
//							  {4.0, 5.0, 6.0},
//							  {7.0, 8.0, 9.0},
//							  {10.0, 11.0, 12.0}});
	cout << theMatrix << endl;
	cout << theMatrix.determinant() << endl;
}

void tocsvExample() {
	String filepath(R"(S:\Documents\TA\ECE 17\FA22\ECE-17-FA22-Discussion\Discussion 7\matrix.csv)");
	Matrix theMatrix({{1.0, 2.0, 3.0},
					  {4.0, 5.0, 6.0},
					  {7.0, 8.0, 9.0},
					  {10.0, 11.0, 12.0}});
	cout << theMatrix << endl;
	theMatrix.toCSV(filepath);
}

void fromcsvExample() {
	String filepath(R"(S:\Documents\TA\ECE 17\FA22\ECE-17-FA22-Discussion\Discussion 7\matrix.csv)");
	cout << Matrix::fromCSV(filepath) << endl;
}