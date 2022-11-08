//
// Created by steph on 11/7/2022.
//

#ifndef DISCUSSION_7_MATRIX_HPP
#define DISCUSSION_7_MATRIX_HPP

#include "Types.hpp"
#include <fstream>
#include <sstream>

class Matrix {
public:
	Matrix() : dimensions({0, 0}) {}
	Matrix(DoubleMatrix aValues) : values(aValues),
		dimensions(aValues.size(), aValues.front().size()) {}

	Matrix multiply(Matrix aMatrix) {
		// Asserts, function guards
		// this (left) aMatrix (right)
		if (dimensions.second != aMatrix.dimensions.first) {
		    throw std::exception();
		}
        DoubleMatrix result(dimensions.first,
                            DoubleVector(aMatrix.dimensions.second));
		for (size_t i = 0; i < dimensions.first; i++) {
		    for (size_t j = 0; j < aMatrix.dimensions.second; j++) {
		        double sum = 0;
		        for (size_t k = 0; k < dimensions.second; k++) {
		            sum += values[i][k] * aMatrix.values[k][j];
		        }
		        result[j][i] = sum;
		    }
		}
		return {result};
	}

	double determinant() {
		return determinant(*this);
	}

	static double determinantSize2(Matrix& aMatrix) {
	    return aMatrix.values[0][0] * aMatrix.values[1][1]
	     - aMatrix.values[0][1] * aMatrix.values[1][0];
	}

	static double determinantHelper(Matrix aMatrix) {
	    if (aMatrix.dimensions == Size{2, 2}) {
	        return determinantSize2(aMatrix);
	    }
	    double result = 0.0;
	    for (size_t i = 0; i < aMatrix.dimensions.first; i++) {
	        DoubleMatrix subMatrix(aMatrix.dimensions.first - 1,
                                DoubleVector(aMatrix.dimensions.first - 1));
	        bool incrementJFlag = false;
	        for (size_t j = 0; j < subMatrix.size(); j++) {
	            if (!incrementJFlag && j == 0) {
	                incrementJFlag = true;
	            }
                bool incrementKFlag = false;
	            for (size_t k = 0; k < subMatrix.size(); k++) {
                    if (!incrementKFlag && k == i) {
                        incrementKFlag = true;
                    }
                    subMatrix[j][k] = aMatrix.values[incrementJFlag ? j + 1 : j][incrementKFlag ? k + 1 : k];
	            }
	        }
	        result += (i % 2 == 0) ? aMatrix.values.front()[i] * determinantHelper({subMatrix}) :
                      (-1.0) * aMatrix.values.front()[i] * determinantHelper({subMatrix});
	    }
	    return result;
	}

	static double determinant(Matrix& aMatrix) {
		if (aMatrix.dimensions.first != aMatrix.dimensions.second) {
		    throw std::exception();
		}
		if (!aMatrix.dimensions.first) {
		    throw std::exception();
		}
		if (aMatrix.dimensions.first == 1) {
		    return aMatrix.values.front().front();
		}
        return determinantHelper(aMatrix);
	}

	Matrix transpose() {
		return transpose(*this);
	}

	static Matrix transpose(Matrix aMatrix) {
		DoubleMatrix result(aMatrix.dimensions.second,
							DoubleVector(aMatrix.dimensions.first));
		for (size_t i = 0; i < aMatrix.dimensions.first; i++) {
		    for (size_t j = 0; j < aMatrix.dimensions.second; j++) {
		        result[j][i] = aMatrix.values[i][j];
		    }
		}
		return {result};
	}

	Size getDimension() {
		return dimensions;
	}

	void toCSV(String filepath) {
		return toCSV(*this, filepath);
	}

	static void toCSV(Matrix& aMatrix, const String& filepath) {
	    ofstream theStream(filepath);
	    if (!theStream.is_open()) {
	        throw std::exception();
	    }
		for (size_t i = 0; i < aMatrix.dimensions.first; i++) {
		    for (size_t j = 0; j < aMatrix.dimensions.second; j++) {
		        theStream << aMatrix.values[i][j] << (j == aMatrix.dimensions.second -1 ? "\n" : ",");
		    }
		}
		theStream.close();
	}

	static Matrix fromCSV(const String& filepath) {
        ifstream theStream(filepath);
        if (!theStream.is_open()) {
            throw std::exception();
        }
		DoubleMatrix result;
        DoubleVector row;
        String temp;
        while (!theStream.eof()) {
            getline(theStream, temp);
            stringstream theSStream(temp);
            String num;
            while (!theSStream.eof()) {
                getline(theSStream, num, ',');
                if (num.empty()) {
                    break;
                }
                row.push_back(stoi(num));
            }
            if (!row.empty()) {
                result.push_back(row);
            }
            row.clear();
        }

		return {result};
	}

	friend std::ostream& operator<<(std::ostream& anOutput, Matrix aMatrix) {
		for (size_t i = 0; i < aMatrix.dimensions.first; i++) {
			for (size_t j = 0; j < aMatrix.dimensions.second; j++) {
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
