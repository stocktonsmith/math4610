**Routine Name**: printMatrix()  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: Given a square matrix *A* and a vector of 1's *y*, this function multiplies them together to compute the right-hand side *b* of the system of equations.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`.  
**Output**: The routine returns a `std::vector<double>` representing the right-hand side of the system of equations.
**Usage Example**:  
*Input*:  

    const int matrixSize = 3;
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
    matrix[0][0] = 4;
    matrix[0][1] = 2;
    matrix[0][2] = -3;
    matrix[1][0] = 0;
    matrix[1][1] = 2;
    matrix[1][2] = -4.25;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 5.5;
    std::vector<double> rhs = multiplySquareMatrixByOnes(matrix);
    std::cout << "RHS:  ";
    for (int i = 0; i < matrixSize; i++) {
        std::cout << rhs[i] << "  ";
    }

*Output*:  

    RHS:  3  -2.25  5.5

This test case accurately determines that the original matrix multiplied by a vector of 1's results in the vector {3, -2.25, 5.5}. This is easily verified by computing the summation of the elements in each of the 3 rows of the original matrix (i.e. 4+2-3 = 3, 0+2-4.25 = -2.25, 0+0+5.5 = 5.5).  

**Implementation**: The following is the code for multiplySquareMatrixByOnes():  

    std::vector<double> multiplySquareMatrixByOnes(const std::vector<std::vector<double>>& matrix)
    {
        std::vector<double> rhsToReturn(matrix.size());
        for (size_t rowNum = 0; rowNum < matrix.size(); rowNum++)
        {
            double total = 0;
            for (size_t colNum = 0; colNum < matrix.size(); colNum++)
            {
                total += matrix[rowNum][colNum];
            }
            rhsToReturn[rowNum] = total;
        }
        return rhsToReturn;
    }

**Last Modified**: October/2023