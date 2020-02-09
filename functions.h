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
    int first{};
    int last{};

public:
    kSmall();

    void newArray();

    void setArraySize();

    int getArraySize();

    void deleteArray();

    int findKth(int, int, int);

    void setK(int);

    int getKth();



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
};




#endif //HOMEWORK_2_FUNCTION_H
