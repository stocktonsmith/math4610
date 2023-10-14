**Routine Name**: printMatrix()  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function provides a convenient way to print out a square matrix, along with its right-hand side, to the screen.  
**Input**: A square matrix must be provided to the routine in the form of a `std::vector<std::vector<double>>`. Be sure to also provide a vector of type `<std::vector<double>` representing the right-hand side of the system of equations. The size of this vector should equal the side length of the square matrix.    
**Output**: The routine prints to the console a square matrix and its right-hand side.  
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
    std::vector<double> rhs = {5, 6, -8};  
    printMatrix(matrix, rhs);  

*Output*:  

    4         2        -3   |           5
    0         2     -4.25   |           6
    0         0       5.5   |          -8

This shows how the printMatrix() function formats its output. The right-hand side is given by everything to the right of the | bars.

**Implementation**: The following is the code for printMatrix():  

    void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& rhs)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                std::cout << std::format("{:>10.3}", matrix[i][j]);
            }
            std::cout << std::format("   |  {:>10.3}", rhs[i]) << std::endl;
        }
        std::cout << std::endl;
    }

**Last Modified**: October/2023