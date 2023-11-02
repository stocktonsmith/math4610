**Routine Name**: squareMatrixToLU  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes in a square matrix *A* and computes the lower-triangular matrix *L* and upper-triangular matrix *U* that satisfies *A = LU*. It should be noted that this function does not account for matrices that run into pivots of 0 during the algorithm.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`. Be sure to initialize the matrix elements - this can be done using nameOfMatrix[i][j] = x, where i is the 0-indexed row number, j is the 0-indexed column number, and x is the double that will be entered at that position.  
**Output**: The routine returns a container in the form of a `std::vector<std::vector<std::vector<double>>>`. The 0th element of this container will be the *L* matrix, and the 1st element of the container will be the *U* matrix.   
**Usage Example**:   
*Input*:  

    const int matrixSize = 3;
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
    std::vector<double> rhs = { 4, 5.1, -2 };
    matrix[0][0] = 5;
    matrix[0][1] = 1;
    matrix[0][2] = -2.25;
    matrix[1][0] = 2;
    matrix[1][1] = -7;
    matrix[1][2] = -4;
    matrix[2][0] = 1.5;
    matrix[2][1] = 3.75;
    matrix[2][2] = -8;

    std::vector<std::vector<std::vector<double>>> LU_container = squareMatrixToLU(matrix);
    printMatrix(LU_container[0], rhs);
    rhs = backSubstitutionLowerTri(LU_container[0], rhs);
    printMatrix(LU_container[1], rhs);

*Output*:  

      1         0         0   |           4
    0.4         1         0   |         5.1
    0.3    -0.466         1   |          -2

      5         1     -2.25   |           4
      0      -7.4      -3.1   |         3.5
      0         0     -8.77   |       -1.57

This test case reduces the original matrix into the lower-triangular matrix *L* (top matrix) and the upper-triangular matrix *U* (bottom matrix). Multiplying *L* and *U* results in the original matrix.

This usage example demonstrates the additional steps of using back substitution to solve a linear system, as the RHS of *U* is computed by finding the solutions to the system shown in *L*. In order to compute the solutions to the original matrix, add the following line to the end of the usage example code (this will also print the solutions to the console):

    std::vector<double> solutions = backSubstitutionUpperTri(LU_container[1], rhs);
    printMatrix(solutions);

In this example, the solutions are <0.99, -0.548, 0.179>. Note that this is the same result computed in the usage example for squareMatrixToUpperTri.

**Implementation**: The following is the code for squareMatrixToLU():  

    std::vector<std::vector<std::vector<double>>> squareMatrixToLU(std::vector<std::vector<double>> matrixU)
    {
        const int matrixSize = matrixU.size();
        std::vector<std::vector<std::vector<double>>> LU_container;
        std::vector<std::vector<double>> matrixL(matrixSize, std::vector<double>(matrixSize, 0));

        for (size_t colIndex = 0; colIndex < matrixU.size(); colIndex++)
        {
            double valOnDiag = matrixU[colIndex][colIndex];
            matrixL[colIndex][colIndex] = 1;
            for (size_t rowIndex = colIndex + 1; rowIndex < matrixU.size(); rowIndex++)
            {
                double ratio = matrixU[rowIndex][colIndex] / valOnDiag;
                matrixL[rowIndex][colIndex] = ratio;
                for (size_t colToReduce = colIndex; colToReduce < matrixU.size(); colToReduce++)
                {
                    matrixU[rowIndex][colToReduce] -= (ratio * matrixU[colIndex][colToReduce]);
                }
            }
        }

        LU_container.push_back(matrixL);
        LU_container.push_back(matrixU);
        return LU_container;
    }

**Last Modified**: October/2023