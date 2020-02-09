#ifndef HOMEWORK_2_FUNCTION_H
#define HOMEWORK_2_FUNCTION_H

#include <iostream>
#include <fstream>

using namespace std;


class kSmall {
private:
    int arraySize{};
    int *anArray = nullptr;
    int k = 0;
    std::string appendage;


public:
    kSmall();

    void newArray(std::ifstream &infile);

    void setArraySize(std::ifstream &infile, int _size);

    inline int getArraySize() { return this->arraySize; }

    inline void deleteArray() { delete[] anArray; }

    int findKth(int _first, int _last, int _value);

    inline void setK(int userInput) { this->k = userInput; }

    inline int getK() { return this->k; }

    inline std::string getAppendage() { return this->appendage; }


    [[noreturn]] static inline void fileNotFound() {
        std::cerr << "File not found!" << std::endl
                  << "Exiting Program!" << std::endl;
        /// @brief winds down stack
        exit(EXIT_FAILURE);
    }

    /// @brief Exits program successfully with message
    inline static std::string exitProgram() {
        std::cout << "Exiting program!" << std::endl;
        /// @brief I used EXIT_SUCCESS here to unwind the stack
        exit(EXIT_SUCCESS);
    }

    static inline void unknownInput() {
        std::cerr << "\nError?! Unknown input.\n" << std::endl;
        kSmall::exitProgram();
    }

    constexpr static const char MENU_TITLE[] =
            "\n\x1b[36m"
            "-----------------------------------\n"
            "|            Main Menu            |\n"
            "-----------------------------------\n"
            "\n\x1b[0m";

    int userInputForK(int userInputForK) {
        std::cin.clear();

        cout << "This program helps you find the Kth smallest element in a dataset." << endl
             << "Please enter your choice for K between 1 and " << this->arraySize << std::endl
             << "> ";
        cin >> userInputForK;
        if (userInputForK % 100 == 1) appendage = "st";
        else if (userInputForK % 100 == 2) appendage = "nd";
        else if (userInputForK % 100 == 3) appendage = "rd";
        else appendage = "th";
        return userInputForK;
    }

};


#endif //HOMEWORK_2_FUNCTION_H
