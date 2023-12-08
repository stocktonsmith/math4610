**Routine Name**: gaussSeidel  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the Gauss-Seidel method for solving linear systems of the form Ax = b. Be aware that this function is not likely to work on singular matrices.  
**Input**: The function requires five parameters: a `std::vector<std::vector<double>>` representing the matrix, a `std::vector<double>` representing the RHS of the system, another `std::vector<double>` representing the initial guess vector, a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting. Be sure that all vectors are the same size.  
**Output**: The routine returns the solution vector of the system in the form of a `std::vector<double>`. Its accuracy can be verified by substituting the values back into the system.  
**Usage Example**:  
*Input*:  

    const int matrixSize = 3;
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
    matrix[0][0] = 6;
    matrix[0][1] = 2;
    matrix[0][2] = 1;

    matrix[1][0] = 4;
    matrix[1][1] = 7;
    matrix[1][2] = 2;

    matrix[2][0] = 1;
    matrix[2][1] = 3;
    matrix[2][2] = 5;

    std::vector<double> rhs{ 13, 24, 22 };
    std::vector<double> initialVector{ 8, 2, 4 };
    double tol = 0.000001;
    int maxIter = 1000;

    std::cout << "\t===== GAUSS - SEIDEL =====" << std::endl;
    std::vector<double> solutions = gaussSeidel(matrix, rhs, initialVector, tol, maxIter);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        std::cout << std::format("X{:<3} = ", i + 1) << solutions[i] << "   ";
        if ((i + 1) % 5 == 0)
        {
            std::cout << std::endl;
        }
    }

*Output*:  

    ===== GAUSS - SEIDEL =====
    X1   = 1   X2   = 2   X3   = 3

In this test case, the algorithm accurately solves the linear system represented by 6x + 2y + z = 13, 4x + 7y + 2z = 24, x + 3y + 5z + 22. The correct solutions are found to be x = 1, y = 2, z = 3.  

**Implementation**: The following is the code for gaussSeidel():  

    std::vector<double> gaussSeidel(const std::vector<std::vector<double>> matrix, const std::vector<double> rhs,
	std::vector<double> x0, double tol, int maxIter)
    {
        std::vector<double> prevX(matrix.size());

        double error = 10 * tol;
        int iter = 0;

        while (error > tol && iter < maxIter)
        {
            prevX = x0;
            for (size_t i = 0; i < matrix.size(); i++)
            {
                double sum = 0;
                for (size_t j = 0; j < matrix.size(); j++)
                {
                    if (i != j)
                    {
                        sum += matrix[i][j] * x0[j];
                    }
                }
                x0[i] = (rhs[i] - sum) / matrix[i][i];
            }

            double sum = 0;
            for (size_t i = 0; i < matrix.size(); i++)
            {
                double val = x0[i] - prevX[i];
                sum += val * val;
            }
            error = sqrt(sum);
            iter++;
        }
        return x0;
    }

**Last Modified**: December/2023