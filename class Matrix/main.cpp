#include <iostream>
#include <time.h>
#include "matrix.h"

int main()
{
    setlocale(LC_ALL, "rus");
    srand((unsigned int)time(0));

    Matrix<int> matrix_1(4, 10, 100);
    std::cout << "MATRIX 1: " << matrix_1;

    Matrix<int> matrix_2(4, 10, 100);
    std::cout << "MATRIX 2: " << matrix_2;


// КОПИРУЮЩИЙ КОНСТРУКТОР
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "КОПИРУЮЩИЙ КОНСТРУКТОР" << std::endl;

    Matrix<int> matrix_2_copy = matrix_2;
    std::cout << "matrix 2: " << matrix_2;
    std::cout << "matrix 2 copy: " << matrix_2_copy;


// OPERATOR+
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР+" << std::endl;

    Matrix<int> matrix_for_addition(matrix_1 + matrix_2);
    std::cout << "matrix 1 + matrix 2: " << matrix_for_addition;

// OPERATOR-
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР-" << std::endl;

    Matrix<int> matrix_for_substraction(matrix_1 - matrix_2);
    std::cout << "matrix 1 - matrix 2: " << matrix_for_substraction;

// OPERATOR*
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР*" << std::endl;

    Matrix<int> matrix_for_multiplication(matrix_1 * matrix_2);
    std::cout << "matrix 1 * matrix 2: " << matrix_for_multiplication;

// OPERATOR/
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР/" << std::endl;

    Matrix<int> matrix_for_division(matrix_1 / matrix_2);
    std::cout << "matrix 1 / matrix 2: " << matrix_for_division;


// ФУНКЦИИ MIN() И MAX()
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ФУНКЦИИ MIN() И MAX()" << std::endl;

    std::cout << "минимальное число из matrix 1: " << matrix_1.min() << std::endl;
    std::cout << "максимальное число из matrix 1: " << matrix_1.max() << std::endl << std::endl;


// ОПЕРАТОР[]
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР[]" << std::endl;

    Matrix<int> matrix_for_subscript(4, 10, 100);
    std::cout << "matrix до оператора[]: " << matrix_for_subscript;

    matrix_for_subscript[11] = 11;
    matrix_for_subscript[12] = 12;
    matrix_for_subscript[13] = 13;
    matrix_for_subscript[14] = 14;

    matrix_for_subscript[21] = 21;
    matrix_for_subscript[22] = 22;
    matrix_for_subscript[23] = 23;
    matrix_for_subscript[24] = 24;

    matrix_for_subscript[31] = 31;
    matrix_for_subscript[32] = 32;
    matrix_for_subscript[33] = 33;
    matrix_for_subscript[34] = 34;

    matrix_for_subscript[41] = 41;
    matrix_for_subscript[42] = 42;
    matrix_for_subscript[43] = 43;
    matrix_for_subscript[44] = 44;

    //matrix_3[52] = 100; // индекс вне диапазона

    std::cout << "matrix после оператора[]: " << matrix_for_subscript;


// ОПЕРАТОР>>
    std::cout << std::endl << std::endl << "***********************************" << std::endl;
    std::cout << "ОПЕРАТОР>>" << std::endl;

    Matrix<int> matrix_for_input(2);
    std::cin >> matrix_for_input;

	std::cout << "MATRIX 3 ПОСЛЕ CIN: " << matrix_for_input;

    return 0;
}