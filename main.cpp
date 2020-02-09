
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

int main() {
    std::ifstream infile;
    /// @brief instantiate object
    kSmall kSmall;
    int size = 0;
    /// @brief declare variables
    int first = 0;
    int userInputForK = 0;
    std::string appendage;
    kSmall.setArraySize(infile, size);
    kSmall.getArraySize();
    int last = (kSmall.getArraySize() - 1);
    kSmall.newArray(infile);
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
    partitionIndex = kSmall.findKth(first, last, kSmall.getK());
    std::cout << "The " << userInputForK << appendage
              << " smallest element is " << partitionIndex
              << "." << std::endl;


    kSmall.deleteArray();
    return 0;
}
