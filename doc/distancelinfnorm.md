**Routine Name**: distancelinfNorm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes two vectors as input and returns the linf-norm of the distance between them. Note that this uses the subtractTwoVectors() function from the appendix.  
**Input**: Two vectors are taken as input, each being of type `std::vector<double>`.  
**Output**: The routine returns a double representing the linf-norm of the distance between the two vectors.  
**Usage Example**:   
*Input*:  

    std::vector<double> myVector1 = {3.75, 5, 6};  
    std::vector<double> myVector2 = {-9, 10, 4.5};  
    std::cout << distancelinfNorm(myVector1, myVector2) << std::endl;  

*Output*:  

    12.75

This demonstrates that the linf-norm of the distance between the 2 vectors is 12.75.

**Implementation**: The following is the code for distancelinfNorm():  

    double distancelinfNorm(std::vector<double> vector1, std::vector<double> vector2)
    {
        return linfNorm(subtractTwoVectors(vector1, vector2));
    }

**Last Modified**: October/2023