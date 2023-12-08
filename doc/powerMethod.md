**Routine Name**: powerMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the power method for finding the largest eigenvalue of a matrix.  
**Input**: The function requires four parameters: a `std::vector<std::vector<double>>` representing the matrix, a `std::vector<double>` representing the initial guess vector, a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting. Be sure that all vectors are the same size.  
**Output**: The routine returns a `double` representing the largest eigenvalue of a matrix. Its accuracy can be verified using a matrix calculator.  
**Usage Example**:  
*Input*:  

    const int matrixSize = 4;
    std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
    matrix[0][0] = 10;
    matrix[0][1] = 2;
    matrix[0][2] = 1;
    matrix[0][3] = 1;

    matrix[1][0] = 4;
    matrix[1][1] = 15;
    matrix[1][2] = 2;
    matrix[1][3] = 2;

    matrix[2][0] = 1;
    matrix[2][1] = 3;
    matrix[2][2] = 20;
    matrix[2][3] = 3;

    matrix[3][0] = 1;
    matrix[3][1] = 2;
    matrix[3][2] = 3;
    matrix[3][3] = 4;

    std::vector<double> initialVector{ 8, 2, 4, 3 };
    double tol = 0.00001;
    int maxIter = 1000;

    double eigenvalue1 = powerMethod(matrix, initialVector, tol, maxIter);
    std::cout << "Eigenvalue with largest magnitude is: " << eigenvalue1 << "\n" << std::endl;

*Output*:  

    Eigenvalue found in 26 iterations
    Eigenvalue with largest magnitude is: 22.1567

It is known that the eigenvalues for this matrix are $\lambda_1 \approx 22.157$, $\lambda_2 \approx 14.871$, $\lambda_3 \approx 8.749$, and $\lambda_4 \approx 3.223$. Therefore, this test case for powerMethod() correctly computed the largest eigenvalue.  

**Implementation**: The following is the code for powerMethod():  

    double powerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector, double tol, int maxIter)
    {
        normalizeVector(vector);
        std::vector<double> yVec = multiplySquareMatrixByVec(matrix, vector);
        double eigenvalue = dotProduct(yVec, vector);
        double error = 10 * tol;
        int iter = 0;

        while (error > tol && iter < maxIter)
        {
            std::vector<double> vectorNext = yVec;
            normalizeVector(vectorNext);
            yVec = multiplySquareMatrixByVec(matrix, vectorNext);
            double nextEigenvalue = dotProduct(yVec, vectorNext);
            error = absError(eigenvalue, nextEigenvalue);
            eigenvalue = nextEigenvalue;
            iter++;
        }

        if (iter == maxIter) {
            std::cout << "Max iterations reached. Eigenvalue may be inaccurate." << std::endl;
        }
        else {
            std::cout << "Eigenvalue found in " << iter << " iterations" << std::endl;
        }

        return eigenvalue;
    }

**Last Modified**: December/2023