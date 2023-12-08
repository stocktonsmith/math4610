**Routine Name**: inversePowerMethod  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides an implementation of the inverse power method for finding the eigenvalue with the smallest magnitude in a matrix. This will occur when the shift value $\mu$ is set to $0$. The function can additionally serve as a shifted inverse power method that can find any eigenvalue in the matrix, depending on what value of $\mu$ is specified.  
**Input**: The function requires five parameters: a `std::vector<std::vector<double>>` representing the matrix, a `std::vector<double>` representing the initial guess vector, a `double` representing the shift value $\mu$, a `double` representing the error tolerance for the root, and an `int` representing the maximum number of iterations that the algorithm will run before quitting. Be sure that all vectors are the same size.  
**Output**: The routine returns a `double` representing the smallest eigenvalue of a matrix (or some other eigenvalue depending on the value of $\mu$). Its accuracy can be verified using a matrix calculator.  
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

    double mu = 0;
    double eigenvalueN = inversePowerMethod(matrix, initialVector, mu, tol, maxIter);
    std::cout << "Eigenvalue with smallest magnitude is: " << eigenvalueN << "\n" << std::endl;

*Output*:  

    Eigenvalue found in 9 iterations
    Eigenvalue with smallest magnitude is: 3.22331

It is known that the eigenvalues for this matrix are $\lambda_1 \approx 22.157$, $\lambda_2 \approx 14.871$, $\lambda_3 \approx 8.749$, and $\lambda_4 \approx 3.223$. Therefore, this test case for inversePowerMethod() correctly computed the smallest eigenvalue.  

**Implementation**: The following is the code for inversePowerMethod():  

    double inversePowerMethod(std::vector<std::vector<double>> matrix, std::vector<double> vector,
	double mu, double tol, int maxIter)
    {
        normalizeVector(vector);

        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][i] -= mu;
        }

        std::vector<std::vector<std::vector<double>>> LU_container = squareMatrixToLU(matrix);
        std::vector<double> yVec = backSubstitutionUpperTri(LU_container[1],
            backSubstitutionLowerTri(LU_container[0], vector));

        double eigenvalue = dotProduct(yVec, vector);
        double error = 10 * tol;
        int iter = 0;

        while (error > tol && iter < maxIter)
        {
            std::vector<double> vectorNext = yVec;
            normalizeVector(vectorNext);
            LU_container = squareMatrixToLU(matrix);
            yVec = backSubstitutionUpperTri(LU_container[1],
                backSubstitutionLowerTri(LU_container[0], vectorNext));

            double nextEigenvalue = dotProduct(yVec, vectorNext);
            error = absError(eigenvalue, nextEigenvalue);
            eigenvalue = nextEigenvalue;
            iter++;
        }

        if (iter == maxIter)
        {
            std::cout << "Max iterations reached. Eigenvalue may be inaccurate." << std::endl;
        }
        else {
            std::cout << "Eigenvalue found in " << iter << " iterations" << std::endl;
        }

        return (1 / eigenvalue) + mu;
    }

**Last Modified**: December/2023