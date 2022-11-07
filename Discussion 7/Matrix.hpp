//
// Created by steph on 11/7/2022.
//

#ifndef DISCUSSION_7_MATRIX_HPP
#define DISCUSSION_7_MATRIX_HPP

#include "Types.hpp"

class Matrix {
public:
	Matrix() : dimensions({0, 0}) {}
	Matrix(DoubleMatrix aValues) : values(aValues),
		dimensions(aValues.front().size(), aValues.size()) {}

	Matrix multiply(Matrix& aMatrix) {
		Matrix result;
		// Here
		return result;
	}

	double determinant() {
		return determinant(*this);
	}

	static double determinant(Matrix& aMatrix) {
		// Here
		return 0.0;
	}

	Matrix transpose() {
		return transpose(*this);
	}

	static Matrix transpose(Matrix& aMatrix) {
		DoubleMatrix result(aMatrix.dimensions.first,
							DoubleVector(aMatrix.dimensions.second));
		// Here
		return {result};
	}

	Size getDimension() {
		return dimensions;
	}

	void toCSV(String filepath) {
		return toCSV(*this, filepath);
	}

	static void toCSV(Matrix& aMatrix, String filepath) {
		// Here
	}

	static Matrix fromCSV(String filepath) {
		Matrix result;
		// Here
		return result;
	}

	friend std::ostream& operator<<(std::ostream& anOutput, Matrix aMatrix) {
		for (size_t i = 0; i < aMatrix.dimensions.second; i++) {
			for (size_t j = 0; j < aMatrix.dimensions.first; j++) {
				cout << aMatrix.values[i][j] << " ";
			}
			cout << endl;
		}
		return anOutput;
	}
protected:
	DoubleMatrix values;
	Size dimensions;
};

#endif //DISCUSSION_7_MATRIX_HPP
