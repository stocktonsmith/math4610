**Routine Name**: backSubstitutionLowerTri  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes in a lower triangular matrix, as well as a matrix representing the right-hand side of a system of equations, and solves the system of equations.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`. Be sure to initialize the matrix elements - this can be done using nameOfMatrix[i][j] = x, where i is the 0-indexed row number, j is the 0-indexed column number, and x is the double that will be entered at that position.  
Be sure to also initialize and pass in a vector of type `<std::vector<double>` representing the right-hand side of the system of equations. The size of this vector should equal the side length of the square matrix.    
**Output**: The routine returns a `<std::vector<double>` containing the solutions to the linear equation.  
**Usage Example**:  
*Input*:  

    const int matrixSize = 3;
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
    matrix[0][0] = 5.5;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 2;
    matrix[1][1] = -4.25;
    matrix[1][2] = 0;
    matrix[2][0] = 4;
    matrix[2][1] = 2;
    matrix[2][2] = -3;
    std::vector<double> rhs = { 5, 6, -8 };
    std::vector<double> solutions = backSubstitutionLowerTri(matrix, rhs);
    std::cout << "X1 = " << solutions[0] << ", X2 = " << solutions[1] << ", X3 = " << solutions[2] << std::endl;

*Output*:  

    X1 = 0.909091, X2 = -0.983957, X3 = 3.22282

This test case determined that the solution to the system of equations 5.5x = 5, 2x - 4.25y = 6, 4x + 2y - 3z = -8 is x ≈ 0.909091, y ≈ -0.983957, z ≈ 3.22282.

**Implementation**: The following is the code for backSubstitutionLowerTri():  

    std::vector<double> backSubstitutionLowerTri(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
    {
	    std::vector<double> solutions(matrix.size());

	    for (size_t xNum = 1; xNum <= matrix.size(); xNum++)
	    {
		    double constants = 0;
		    for (size_t constantNum = 1; xNum > constantNum; constantNum++)
		    {
			    constants += (solutions[constantNum - 1] * matrix[xNum - 1][constantNum - 1]);
		    }
		    double result = (rhs[xNum - 1] - constants) / (matrix[xNum - 1][xNum - 1]);
		    solutions[xNum - 1] = result;
	    }

	    return solutions;
    }

**Last Modified**: October/2023