////
//// Created by BK Allen on 2/6/20.
////

#include "functions.h"
#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

/// @brief this function determines the size of the array needed
void kSmall::setArraySize(std::ifstream &infile, int _size) {
    std::string line;
    infile.open("../input.dat");
    while (getline(infile, line)) {
        _size++;
    }
    this->arraySize = _size;
    infile.close();
}///#setArraySize

/// @brief this function creates a new array of the correct size
/// @brief it verifies that the file is present and infile is working
/// @param infile file stream
void kSmall::newArray(std::ifstream &infile) {
    /// @brief sets a static size to array
    anArray = new int[arraySize];
    infile.open("../input.dat");

    if (!infile || infile.fail()) { fileNotFound(); }
    ///@brief peek() returns the next character in the input sequence
    /// @brief without extracting it.
    /// @brief sets flag to eofbit when end of file is reached.
    while (infile.peek() != EOF) {
        for (int n = 0; n < arraySize; ++n) {
            infile >> anArray[n];
        }///#for
    }///#while

    infile.close();
}///#newArray


/// @brief default constructor
kSmall::kSmall() = default;

/// @brief This functions implements the kSmall algorithm
/// @brief by recursively repartitioning the array.
/// @param _first the pivot (zero in our case)
/// @param _last The size of the array
/// @param _value the kth value we are locating
/// @return to itself until kth value determined
int kSmall::findKth(int _first, int _last, int _value) {
    /// @brief declare local variables
    int start = _first;
    int end = _last;
    int partitionIndex = _first;
    int leftPartition;
    int rightPartition;
    int counter = end - start;

    for (int i = 0; i < counter; ++i) {
        if (anArray[partitionIndex] > anArray[partitionIndex + 1]) {

            leftPartition = anArray[partitionIndex];

            rightPartition = anArray[partitionIndex + 1];

            anArray[partitionIndex + 1] = leftPartition;

            anArray[partitionIndex] = rightPartition;
            WHAT_IS(start);
            start++;
            partitionIndex++;

        } else if (anArray[partitionIndex] < anArray[partitionIndex + 1]) {

            leftPartition = anArray[partitionIndex + 1];
            rightPartition = anArray[end];
            anArray[end] = leftPartition;
            anArray[partitionIndex + 1] = rightPartition;
            --end;

        }///#else if
    }///#for
    /// @brief if partition is the same as the k value return that value
    if (partitionIndex == _value) {
        return anArray[_value];
        /// @brief if partition is less than, recur right side
    } else if (partitionIndex < _value) {
        return findKth(partitionIndex + 1, _last, _value);
        /// @brief if partition is greater than, recur left side
    } else {
        return findKth(_first, partitionIndex - 1, _value);
    }
}///# find Kth
/// @brief
/// @param userInputForK
/// @return
int kSmall::userInputForK(int userInputForK) {
    std::cout << "This program helps you find the Kth smallest element in a dataset." << std::endl
              << "Please enter your choice for K between 1 and " << arraySize << std::endl
              << "> ";
    std::cin >> userInputForK;
    setOrdinal(userInputForK);
    return userInputForK;
}///# userInputForK

/// @brief sets the ordinal of k
/// @param userInputForK integer value of k
/// @return string value of matcing ordinal
std::string kSmall::setOrdinal(int userInputForK) {
    if (userInputForK % 100 == 1) ordinal = "st";
    else if (userInputForK % 100 == 2) ordinal = "nd";
    else if (userInputForK % 100 == 3) ordinal = "rd";
    else ordinal = "th";
    return ordinal;
}///#setOrdinal


