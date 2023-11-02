**Routine Name**: multiplySquareMatrixByVec  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: Given a square matrix *A* and a vector *y*, this function multiplies *A* * *y* to compute the right-hand side *b* of the system of equations.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`.  
A `std::vector<double>` representing the RHS must also be provided.   
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
    matrix[2][0] = 6;
    matrix[2][1] = 0;
    matrix[2][2] = 5.5;

    std::vector<double> vec;
    vec.push_back(2);
    vec.push_back(3.5);
    vec.push_back(-4);

    std::vector<double> rhs = multiplySquareMatrixByVec(matrix, vec);
    std::cout << "RHS:  ";
    for (int i = 0; i < matrixSize; i++) {
        std::cout << rhs[i] << "  ";
    }

*Output*:  

    RHS:  27  24  -10

This test case accurately determines that the original matrix multiplied by the vector {2, 3.5, -4} results in the vector {27, 24, -10}.  

**Implementation**: The following is the code for multiplySquareMatrixByVec():  

    std::vector<double> multiplySquareMatrixByVec(const std::vector<std::vector<double>>& matrix,
	const std::vector<double>& rhs)
    {
        std::vector<double> rhsToReturn(matrix.size());
        for (size_t rowNum = 0; rowNum < matrix.size(); rowNum++)
        {
            double total = 0;
            for (size_t colNum = 0; colNum < matrix.size(); colNum++)
            {
                total += matrix[rowNum][colNum] * rhs[colNum];
            }
            rhsToReturn[rowNum] = total;
        }
        return rhsToReturn;
    }

**Last Modified**: November/2023
