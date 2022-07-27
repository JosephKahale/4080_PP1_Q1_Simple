#include <iostream>
#include <chrono>

void loadValues(float mat[][100], int, int);
void load10Values(float mat[][100], int, int);

void multiplyMatrix(float mat[][100], float mat2[][100], float mat3[][100], int, int, int, int);
void subtractMatrix(float mat[][100], float mat2[][100], float mat3[][100], int, int, int, int);
void addMatrix(float mat[][100], float mat2[][100], float mat3[][100], int, int, int, int);
void displayVals(float mat3[][100], int, int);

int main() {
	int matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol;
	int choice;

	choice = -1;

	do {
		float matrix[100][100];
		float matrix2[100][100];
		float matrix3[100][100];
		std::cout << "Enter Row Size of Matrix 1" << std::endl;
		std::cin >> matOneSizeRow;
		std::cout << "Enter Col Size of Matrix 1" << std::endl;
		std::cin >> matOneSizeCol;
		std::cout << "Enter Row Size of Matrix 2" << std::endl;
		std::cin >> matTwoSizeRow;
		std::cout << "Enter Col Size of Matrix 2" << std::endl;
		std::cin >> matTwoSizeCol;

		loadValues(matrix, matOneSizeRow, matOneSizeCol);
		loadValues(matrix2, matTwoSizeRow, matTwoSizeCol);
		std::cout << "Matrix Values Saved!" << std::endl;

		do {
			std::cout << "Please Make a Selection: " << std::endl;
			std::cout << "	1. Create a new matrix." << std::endl;
			std::cout << "	2. Add Current Matricies." << std::endl;
			std::cout << "	3. Subtract Current Matricies." << std::endl;
			std::cout << "	4. Multiply Current Matricies." << std::endl;
			std::cout << "	5. Quit the Program." << std::endl;
			std::cin >> choice;

			switch (choice)
			{
			case 1:
			{

				break;
			}
			case 2:
			{
				auto start = std::chrono::steady_clock::now();

				addMatrix(matrix, matrix2, matrix3, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();

				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;
				displayVals(matrix3, matOneSizeRow, matOneSizeCol);
				break;
			}
			case 3:
			{
				auto start = std::chrono::steady_clock::now();
				subtractMatrix(matrix, matrix2, matrix3, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();

				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;
				displayVals(matrix3, matOneSizeRow, matOneSizeCol);
				break;
			}
			case 4:
			{
				auto start = std::chrono::steady_clock::now();
				multiplyMatrix(matrix, matrix2, matrix3, matOneSizeRow, matOneSizeCol, matTwoSizeRow, matTwoSizeCol);
				auto end = std::chrono::steady_clock::now();
				std::cout << "Elapsed time in nanoseconds: "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
					<< " ns" << std::endl;
				displayVals(matrix3, matOneSizeRow, matOneSizeCol);

				break;
			}
			case 5:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				std::cout << "Incorrect choice, Please try again." << std::endl;
				break;
			}
		} while (choice != 1 && choice != 5);

	} while (choice != 5);

	return 0;
}

void loadValues(float mat[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Please enter the float values for i: " << i << " | j: " << j << std::endl;
			std::cin >> mat[i][j];
		}
	}
}

void load10Values(float mat[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << "Please enter the float values for i: " << i << " | j: " << j << std::endl;
			mat[i][j] = 2.56;
		}
	}
}

void multiplyMatrix(float mat[][100], float mat2[][100], float mat3[][100], int row, int col, int row2, int col2) {
	if (col2 != row) {
		std::cout << "Incompatible types: Please Use Compatible Dimension Matrix.";
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat3[i][j] = 0;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col2; j++) {
				for (int k = 0; k < col; k++) {
					mat3[i][j] += mat[i][k] * mat2[k][j];
				}
			}
		}
	}
}

void subtractMatrix(float mat[][100], float mat2[][100], float mat3[][100], int row, int col, int row2, int col2) {
	if (row != row2 || col != col2) {
		std::cout << "Incompatible types: Please Use Same Dimension Matrix.";
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat3[i][j] = mat[i][j] - mat2[i][j];
			}
		}
	}
}

void addMatrix(float mat[][100], float mat2[][100], float mat3[][100], int row, int col, int row2, int col2) {
	if (row != row2 || col != col2) {
		std::cout << "Incompatible types: Please Use Same Dimension Matrix.";
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat3[i][j] = mat[i][j] + mat2[i][j];
			}
		}
	}
}

void displayVals(float mat3[][100], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << mat3[i][j] << " ";
		}
		std::cout << std::endl;
	}
}