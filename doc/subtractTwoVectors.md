**Routine Name**: subtractTwoVectors  
**Author**: Stockton Smith  
**Language**: C++  
**Description**: This function takes two vectors and returns a vector representing the distance between them.  
**Input**: Two vectors of type `std::vector<double>` are provided.  
**Output**: The routine returns a vector of type `std::vector<double>` representing the distance between the original two vectors.  
**Usage Example**:   
*Input*:  

    std::vector<double> myVector1 = {3, 5, 8};  
    std::vector<double> myVector2 = {1, 0, 9};  
    std::vector<double> diffVector = subtractTwoVectors(myVector1, myVector2);  
    std::cout << "{" << diffVector[0] << ", " << diffVector[1] << ", " << diffVector[2] << "}";

*Output*:  

    {-2, -5, 1}

This shows the distance between the original 2 vectors to be -2 in the x-direction, -5 in the y-direction, and 1 in the z-direction.

**Implementation**: The following is the code for subtractTwoVectors():  

    std::vector<double> subtractTwoVectors(std::vector<double> vector1, std::vector<double> vector2)
    {
        std::vector<double> newVector;
        for (int i = 0; i < vector2.size(); i++)
        {
            newVector.push_back(vector2[i] - vector1[i]);
        }

        return newVector;
    }

**Last Modified**: October/2023