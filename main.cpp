
#include "functions.h"

int main() {
    ifstream inFile("../input.dat");
    /// @brief instantiate object
    kSmall kSmall;
    /// @brief declare variables
    int first = 0;
    int userInputForK = 0;
    std::string appendage;
    kSmall.setArraySize();
    kSmall.getArraySize();
    int last = (kSmall.getArraySize() - 1);
    kSmall.newArray();
    cout << "This program helps you find the Kth smallest element in a dataset." << endl
         << "Please enter your choice for K." << std::endl
         << "> ";
    cin >> userInputForK;
    if (userInputForK % 100 == 1) appendage = "st";
    else if (userInputForK % 100 == 2) appendage = "nd";
    else if (userInputForK % 100 == 3) appendage = "rd";
    else appendage = "th";

    kSmall.setK(userInputForK - 1);

    int partitionIndex;
    // returning partitionIndex value for Kth
    partitionIndex = kSmall.findKth(first, last, kSmall.getKth());
    std::cout << "The " << userInputForK << appendage
              << " smallest element is " << partitionIndex
              << "." << std::endl;


    kSmall.deleteArray();
    return 0;
}
