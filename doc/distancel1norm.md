**Routine Name**: distancel1Norm  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes two vectors as input and returns the l1-norm of the distance between them. Note that this uses the subtractTwoVectors() function from the appendix.  
**Input**: Two vectors are taken as input, each being of type `std::vector<double>`.  
**Output**:  The routine returns a double representing the l1-norm of the distance between the two vectors.  
**Usage Example**:   
*Input*:  

    std::vector<double> myVector1 = {2, 1, 3};  
    std::vector<double> myVector2 = {8, -1.5, -4};  
    std::cout << distancel1Norm(myVector1, myVector2) << std::endl;  

*Output*:  

    15.5

This demonstrates that the l1-norm of the distance between the 2 vectors is 15.5.

**Implementation**: The following is the code for distancel1Norm():  

    double distancel1Norm(std::vector<double> vector1, std::vector<double> vector2)
    {
        return l1Norm(subtractTwoVectors(vector1, vector2));
    }

**Last Modified**: October/2023