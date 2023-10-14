**Routine Name**: squareMatrixToUpperTri  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes in a reference to a square matrix and converts it into a matrix in upper-triangular form. It should be noted that this function does not account for matrices that run into pivots of 0 during the algorithm.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`. Be sure to initialize the matrix elements - this can be done using nameOfMatrix[i][j] = x, where i is the 0-indexed row number, j is the 0-indexed column number, and x is the double that will be entered at that position.  
Be sure to also initialize and pass in a vector of type `<std::vector<double>` representing the right-hand side of the system of equations. The size of this vector should equal the side length of the square matrix.  
**Output**: Once the routine is completed, the matrix will have been updated into an equivalent upper triangular matrix (and the RHS is reduced appropriately as well). This occurs using references, so nothing is explicitly returned.  
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

    squareMatrixToUpperTri(matrix, rhs);
    printMatrix(matrix, rhs);

*Output*:  

    5         1     -2.25   |           4
    0      -7.4      -3.1   |         3.5
    0         0     -8.77   |       -1.57

This test case reduces the original matrix into the above equivalent upper triangular matrix, which consists entirely of 0's below the main diagonal.

**Implementation**: The following is the code for squareMatrixToUpperTri():  

    void squareMatrixToUpperTri(std::vector<std::vector<double>>& matrix, std::vector<double>& rhs)
    {
        for (size_t colIndex = 0; colIndex < matrix.size(); colIndex++)
        {
            double valOnDiag = matrix[colIndex][colIndex];
            for (size_t rowIndex = colIndex + 1; rowIndex < matrix.size(); rowIndex++)
            {
                double ratio = matrix[rowIndex][colIndex] / valOnDiag;
                for (size_t colToReduce = colIndex; colToReduce < matrix.size(); colToReduce++)
                {
                    matrix[rowIndex][colToReduce] -= (ratio * matrix[colIndex][colToReduce]);
                    std::cout << std::endl;
                }
                rhs[rowIndex] -= (ratio * rhs[colIndex]);
            }
        }
    }

**Last Modified**: October/2023