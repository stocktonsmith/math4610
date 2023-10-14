**Routine Name**: linreg  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function computes linear regression using the least squares method for two vectors. Two vectors are taken as input, and the equation for the line of best fit is printed as the output.  
**Input**: Two vectors of type `std::vector<double>` must be provided.  
**Output**: The routine returns a `std::vector<double>`. Index 0 of this vector holds the best-fit slope, and index 1 holds the best-fit y-intercept.  
**Usage Example**:   
*Input*:  

    std::vector<double> vector1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<double> vector2 = {1.5, 3.8, 6.7, 9.0, 11.2, 13.6, 16.0};
    std::vector<double> result = linreg(vector1, vector2);
    std::cout << "BEST FIT: Y = " << result[0] << "X + " << result[1] << std::endl;

*Output*:  

    BEST FIT: Y = 2.41429X + -0.828571

This test case shows that the line of best fit for the two vectors has a slope of 2.41429 and a y-intercept of -0.828571.

**Implementation**: The following is the code for linreg():  

    std::vector<double> linreg(std::vector<double> vector1, std::vector<double> vector2)
    {
    	double vecSize = static_cast<double>(vector1.size());
    	double slope = 0.0;
    	double yIntercept = 0.0;
    	double vec1Sum = 0;
    	double vec2Sum = 0;
    	double vecProductSum = 0;
    	double vec1SquaredSum = 0;
    
    	for (int i = 0; i < vecSize; i++)
    	{
    		vec1Sum += vector1[i];
    		vec2Sum += vector2[i];
    		vecProductSum += (vector1[i] * vector2[i]);
    		vec1SquaredSum += (vector1[i] * vector1[i]);
    	}
    
    	double numerator = (vecSize * vecProductSum) - (vec1Sum * vec2Sum);
    	double denominator = (vecSize * vec1SquaredSum) - (vec1Sum * vec1Sum);
    	slope = numerator / denominator;
    	yIntercept = ((vec2Sum)-(slope * vec1Sum)) / (vecSize);
    
    	std::vector<double> bestFitVector = { slope, yIntercept };
    
    	return bestFitVector;
    }

**Last Modified**: October/2023
