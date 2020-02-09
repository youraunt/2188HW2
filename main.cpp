
#include "functions.h"

#define WHAT_IS(x) std::cerr << #x << " is " << (x) << std::endl;

int main() {
    try {
        /// @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        std::ifstream infile;
        /// @brief instantiate object
        kSmall kSmall;
        int size = 0;
        /// @brief declare variables
        int first = 0;
        int userInputForK = 0;
        kSmall.setArraySize(infile, size);
        kSmall.getArraySize();
        int last = (kSmall.getArraySize() - 1);
        kSmall.newArray(infile);
        userInputForK = kSmall.userInputForK(userInputForK);
        if (userInputForK > kSmall.getArraySize() || userInputForK < 1) {
            std::cout << "\n\x1b[31mInvalid input!\n\x1b[0m" << std::endl;
            kSmall.userInputForK(userInputForK);
        }
        kSmall.setK(userInputForK - 1);

        int partitionIndex;
        // returning partitionIndex value for Kth
        partitionIndex = kSmall.findKth(first, last, kSmall.getK());
        std::cout << "The " << userInputForK << kSmall.getAppendage()
                  << " smallest element is " << partitionIndex
                  << "." << std::endl;


        kSmall.deleteArray();
    } catch (const std::exception &) {
        kSmall::unknownInput();
    }///#catch
}
