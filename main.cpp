/*******************************************************
*  Name         : Brice Allen
*  Student ID   : 107452188
*  Class        : CSC 2421
*  HW#          : 2
*  Due Date     : 11:59 PM Feb. 10, 2020
*  File Name    : 2188HW2
*******************************************************/
#include "functions.h"
/// @brief this macro lets you output variables
/// @brief I use it to debug
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
        /// @brief sets the size of the array
        kSmall.setArraySize(infile, size);
        kSmall.getArraySize();
        /// @brief sets the last element of the array
        int last = (kSmall.getArraySize() - 1);
        /// @brief creates new array
        kSmall.newArray(infile);
        /// @brief checks data to see if it is in range
        while (true) {
            userInputForK = kSmall.userInputForK(userInputForK);
            while (((userInputForK > kSmall.getArraySize() || userInputForK < 1))) {
                std::cout << "\n\x1b[31mInvalid input!\n\x1b[0m" << std::endl;
                userInputForK = kSmall.userInputForK(userInputForK);
            }
            break;
        }///#while
        /// @brief once data is validated sets kth value
        kSmall.setK(userInputForK - 1);
        /// @brief display results to user
        std::cout << "The " << userInputForK << kSmall.getOrdinal()
                  << " smallest element is " << kSmall.findKth(first, last, kSmall.getK())
                  << "." << std::endl;
        /// @brief release memory
        kSmall.deleteArray();
    } catch (const std::exception &) {
        kSmall::unknownInput();
    }///#catch
}///#main
