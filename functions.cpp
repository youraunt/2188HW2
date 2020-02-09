////
//// Created by BK Allen on 2/6/20.
////

#include "functions.h"

#include <sstream>

/// @brief
void kSmall::newArray() {
    ifstream infile;
    string line;
    anArray = new int[arraySize];

    infile.open("../input.dat");

    if (!infile || infile.fail()) { fileNotFound(); }

    while (infile.peek() != EOF) {
        cout << "Opened!" << endl;

        for (int n = 0; n < arraySize; ++n) {
            infile >> anArray[n];

        }
    }

    infile.close();
}

/// @brief
void kSmall::setArraySize() {
    int size = 0;
    string line;

    ifstream inFile("../input.dat");

    while (getline(inFile, line)) {
        size++;
    }
    arraySize = size;
    inFile.close();
}

/// @brief
/// @return
int kSmall::getArraySize() {
    return arraySize;
}

/// @brief
void kSmall::deleteArray() {
    delete[] anArray;
}

/// @brief
kSmall::kSmall() = default;

/// @brief
/// @param first
/// @param last
/// @param value
/// @return
int kSmall::findKth(int first, int last, int value) {
    int start = first;
    int end = last;
    int partitionIndex = first;
    int temp1;
    int temp2;
    unsigned int counter = end - start;

    for (unsigned int i = 0; i < counter; ++i) {
        if (anArray[partitionIndex] > anArray[partitionIndex + 1]) {

            temp1 = anArray[partitionIndex];

            temp2 = anArray[partitionIndex + 1];

            anArray[partitionIndex + 1] = temp1;

            anArray[partitionIndex] = temp2;

            start++;
            partitionIndex++;

        } else if (anArray[partitionIndex] < anArray[partitionIndex + 1]) {

            temp1 = anArray[partitionIndex + 1];
            temp2 = anArray[end];
            anArray[end] = temp1;
            anArray[partitionIndex + 1] = temp2;
            end--;

        }
    }

    if (partitionIndex == value) {
        return anArray[value];
    } else if (partitionIndex < value) {
        return findKth(partitionIndex + 1, last, value);
    } else {
        return findKth(first, partitionIndex - 1, value);
    }
}

/// @brief
/// @return
int kSmall::getKth() {
    return this->k;
}

/// @brief
/// @param userInput
void kSmall::setK(int userInput) {
    this->k = userInput;
}

