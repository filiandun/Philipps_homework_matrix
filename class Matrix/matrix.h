#pragma once
#include <iostream>


template<typename T>
class Matrix
{
public:
	Matrix() // конструктор
	{
		this->size = 5;

		this->array = new T *[this->size];
		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			this->array[i] = new T[this->size];
		}

		this->array[this->size][this->size] = '\0';
	}


	Matrix(unsigned long long int size) // конструктор с размером
	{
		this->size = size;

		this->array = new T* [this->size];
		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			this->array[i] = new T [this->size];
		}
	}


	Matrix(unsigned long long int size, unsigned long long int random_from, unsigned long long int random_to) // конструктор с рандомом
	{
		this->size = size;

		this->array = new T * [this->size];
		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			this->array[i] = new T[this->size];
		}


		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				this->array[i][j] = rand() % (random_to - random_from) + random_from;
			}
		}
	}


	Matrix(const Matrix& matrix) // копирующий конструктор
	{
		this->size = matrix.size;

		this->array = new T * [this->size];
		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			this->array[i] = new T[this->size];
		}


		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				this->array[i][j] = matrix.array[i][j];
			}
		}
	}




	~Matrix() // деструктор
	{
		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			delete[] this->array[i];
		}
		delete[] this->array;
	}


private:
	unsigned long long int size; // размер массива
	T** array; // двухмерный массив


public:
	T min()
	{
		T min = this->array[0][0];

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				if (min > this->array[i][j])
				{
					min = this->array[i][j];
				}
			}
		}

		return min;
	}

	T max()
	{
		T max = this->array[0][0];

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				if (max < this->array[i][j])
				{
					max = this->array[i][j];
				}
			}
		}

		return max;
	}






	Matrix operator+(const Matrix& matrix)
	{
		Matrix addition(this->size);

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				addition.array[i][j] = this->array[i][j] + matrix.array[i][j];
			}
		}

		return addition;
	}


	Matrix operator-(const Matrix& matrix)
	{
		Matrix substraction(this->size);

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				substraction.array[i][j] = this->array[i][j] - matrix.array[i][j];
			}
		}

		return substraction;
	}


	Matrix operator*(const Matrix& matrix)
	{
		Matrix multiplictaion(this->size);

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				multiplictaion.array[i][j] = this->array[i][j] * matrix.array[i][j];
			}
		}

		return multiplictaion;
	}


	Matrix operator/(const Matrix& matrix)
	{
		Matrix division(this->size);

		for (unsigned long long int i = 0; i < this->size; ++i)
		{
			for (unsigned long long int j = 0; j < this->size; ++j)
			{
				division.array[i][j] = this->array[i][j] / matrix.array[i][j];
			}
		}

		return division;
	}






	T& operator[](unsigned long long int index)
	{
		if (index / 10 - 1 < this->size)
		{
			return this->array[index / 10 - 1][index % 10 - 1]; // единственное, если матрица будет размером больше 10, то такой вариант не прокатит
		}

		std::cerr << "ОШИБКА: ИНДЕКС ВНЕ ДИАПАЗОНА" << std::endl;
		exit(index);
	}





	friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
	{
		output << std::endl << std::endl << "№";
		for (unsigned long long int i = 0; i < matrix.size; ++i)
		{
			output << "\t" << i + 1;
		}

		for (unsigned long long int i = 0; i < matrix.size; ++i)
		{
			output << std::endl << std::endl << std::endl << i + 1 << "\t";
			for (unsigned long long int j = 0; j < matrix.size; ++j)
			{
				output << matrix.array[i][j] << "\t";
			}
		}
		output << std::endl << std::endl;

		return output;
	}


	friend std::istream& operator>>(std::istream& input, Matrix& matrix)
	{
		matrix.array = new T* [matrix.size];
		for (unsigned long long int i = 0; i < matrix.size; ++i)
		{
			matrix.array[i] = new T[matrix.size];
		}

		for (unsigned long long int i = 0; i < matrix.size; ++i)
		{
			for (unsigned long long int j = 0; j < matrix.size; ++j)
			{
				std::cout << "Введите элемент матрицы под индексами [" << i + 1 << "] [" << j + 1 << "]: ";
				input >> matrix.array[i][j];

				while (input.fail())
				{
					input.clear();
					input.ignore();

					std::cout << "Неверное значение, введите элемент матрицы под индексами [" << i + 1 << "] [" << j + 1 << "] повторно: ";
					input >> matrix.array[i][j];
				}
			}
		}
		return input;
	}
};


