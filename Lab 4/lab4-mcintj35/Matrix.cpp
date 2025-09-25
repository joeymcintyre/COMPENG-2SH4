
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

//this is the default constructor
Matrix::Matrix()
{
	rowsNum = 3;
	colsNum = 3;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = 0;

}

//this is an aditional constructor - creates matric on the heap with dimensiopns specified by row and col
//if row and col are invalid (<= 0), they are set to the default size of 3
Matrix::Matrix( int row, int col )
{
	rowsNum = (row > 0) ? row : 3;
	colsNum = (col > 0) ? col : 3;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum]();
	}
}

//another additional constructor - creates matrix on heap with dimensions specified by row and col
//then copys all values into the 2d integer array "table"
Matrix::Matrix(int row, int col, int** table)
{
	rowsNum = row;
	colsNum = col;
	matrixData = new int*[rowsNum];
	for (int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum];

		for (int j = 0; j < colsNum; j++)
		{
			matrixData[i][j] = table[i][j];
		}
	}
}

//deconstructor - needed to release the dynamically allocated memory, otherwise there would be a memory leak
Matrix::~Matrix() 
{
    for (int i = 0; i < rowsNum; i++) 
	{
        delete[] matrixData[i]; 
    }

    delete[] matrixData; 
}

//rule of minimum 4 - deep copy - copy constructor
Matrix::Matrix(const Matrix &other) 
{
    rowsNum = other.rowsNum;
    colsNum = other.colsNum;

    matrixData = new int*[rowsNum];

    for (int i = 0; i < rowsNum; i++) 
	{
        matrixData[i] = new int[colsNum];

        for (int j = 0; j < colsNum; j++) 
		{
            matrixData[i][j] = other.matrixData[i][j];
        }
    }
}

//rule of minimum 4 - deep copy - copy assignment opperator
Matrix& Matrix::operator=(const Matrix &other) 
{
    if (this == &other) 
	{
        return *this; 
    }

    for (int i = 0; i < rowsNum; i++) 
	{
        delete[] matrixData[i];
    }

    delete[] matrixData;

    rowsNum = other.rowsNum;
    colsNum = other.colsNum;

    matrixData = new int*[rowsNum];
    for (int i = 0; i < rowsNum; i++) 
	{
        matrixData[i] = new int[colsNum];

        for (int j = 0; j < colsNum; j++) 
		{
            matrixData[i][j] = other.matrixData[i][j];
        }
    }

    return *this;
}

//getter method - returns value of matric element at (i,j) (if in range)
int Matrix::getElement(int i, int j)
{
	if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum) 
	{
        throw std::out_of_range("Invalid indexes.");
    }

    return matrixData[i][j];
}

//getter method - returns number or rows
int Matrix::getsizeofrows()
{
	return rowsNum;
}

//getter method - returns number of columns
int Matrix::getsizeofcols()
{
    return colsNum;
}

//setter method - sets value of matrix element at (i,j) with x (if in range)
bool Matrix::setElement(int x, int i, int j)
{
    if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum) 
	{
        return false;
    }

    matrixData[i][j] = x;
    return true;
}

//copy operation method - creates copy of the matrix
Matrix Matrix::copy()
{
	Matrix copy = Matrix(rowsNum, colsNum);

	for(int i = 0; i < rowsNum; i++)
	{
		for(int j = 0; j < colsNum; j++)
		{
			copy.setElement(matrixData[i][j], i, j);
		}
	}

    return copy;
}

//matrix addition method - adds matrix m to the current matrix (if they are same size)
void Matrix::addTo( Matrix m )
{
	if (rowsNum != m.getsizeofrows() || colsNum != m.getsizeofcols()) 
	{
        throw std::invalid_argument("Invalid operation.");
    }

    for (int i = 0; i < rowsNum; i++) 
	{
        for (int j = 0; j < colsNum; j++) 
		{
            matrixData[i][j] += m.getElement(i, j);
        }
    }
}

//disguised getter method - gets and returns the submatrix between (0,0) and (i,j) (the upper-left submatrix)
Matrix Matrix::subMatrix(int i, int j)
{
    if (i < 0 || i >= rowsNum || j < 0 || j >= colsNum) 
	{
        throw std::out_of_range("Submatrix not defined.");
    }

    Matrix sub(i + 1, j + 1);
    for (int r = 0; r <= i; r++) 
	{
        for (int c = 0; c <= j; c++) 
		{
            sub.setElement(matrixData[r][c], r, c);
        }
    }

    return sub;
}

//string conversion method - outputs the matrix contents in the correct format
string Matrix::toString()
{
	string output;

    for (int i = 0; i < rowsNum; i++) 
	{
        for (int j = 0; j < colsNum; j++) 
		{
            output += to_string(matrixData[i][j]) + " ";
        }

        output += "\n";
    }

	return output;
}