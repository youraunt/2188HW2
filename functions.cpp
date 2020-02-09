////
//// Created by BK Allen on 2/6/20.
////

#include "functions.h"

#include <sstream>

/// @brief
void kSmall::newArray(std::ifstream &infile) {
    anArray = new int[arraySize];
    infile.open("../input.dat");

    if (!infile || infile.fail()) { fileNotFound(); }

    while (infile.peek() != EOF) {
        for (int n = 0; n < arraySize; ++n) {
            infile >> anArray[n];
        }
    }

    infile.close();
}

/// @brief
void kSmall::setArraySize(std::ifstream &infile, int _size) {
    string line;
    infile.open("../input.dat");
    while (getline(infile, line)) {
        _size++;
    }
    this->arraySize = _size;
    infile.close();
}

///// @brief
///// @return
//int kSmall::getArraySize() {
//    return this->arraySize;
//}

///// @brief
//void kSmall::deleteArray() {
//    delete[] anArray;
//}

/// @brief
kSmall::kSmall() = default;

/// @brief
/// @param _first
/// @param _last
/// @param _value
/// @return
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

            start++;
            partitionIndex++;

        } else if (anArray[partitionIndex] < anArray[partitionIndex + 1]) {

            leftPartition = anArray[partitionIndex + 1];
            rightPartition = anArray[end];
            anArray[end] = leftPartition;
            anArray[partitionIndex + 1] = rightPartition;
            end--;

        }
    }

    if (partitionIndex == _value) {
        return anArray[_value];
    } else if (partitionIndex < _value) {
        return findKth(partitionIndex + 1, _last, _value);
    } else {
        return findKth(_first, partitionIndex - 1, _value);
    }
}

///// @brief
///// @return
//int kSmall::getK() {
//    return this->k;
//}

///// @brief
///// @param userInput
//void kSmall::setK(int userInput) {
//    this->k = userInput;
//}

