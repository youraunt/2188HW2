/*******************************************************
*  Name         : Brice Allen
*  Student ID   : 107452188
*  Class        : CSC 2421
*  HW#          : 2
*  Due Date     : Feb. 10, 2020
*  File Name    : 2188HW2
*******************************************************/
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

int main() {
    try {
        /// @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief open file stream
        std::ifstream infile;
        /// @brief instantiate object
        kSmall kSmall;
        /// @brief declare variables
        int size = 0;
        int first = 0;
        int userInputForK = 0;

        kSmall.setArraySize(infile, size);
        kSmall.getArraySize();
        int last = (kSmall.getArraySize() - 1);
        kSmall.newArray(infile);

        while (true) {
            userInputForK = kSmall.userInputForK(userInputForK);
            if (((userInputForK > kSmall.getArraySize() || userInputForK < 1))) {
                std::cout << "\n\x1b[31mInvalid input!\n\x1b[0m" << std::endl;
                userInputForK = kSmall.userInputForK(userInputForK);
            }
            break;
        }
        kSmall.setK(userInputForK - 1);

        std::cout << "The " << userInputForK << kSmall.getAppendage()
                  << " smallest element is " << kSmall.findKth(first, last, kSmall.getK())
                  << "." << std::endl;
        kSmall.deleteArray();
    } catch (const std::exception &) {
        kSmall::unknownInput();
    }///#catch
}
