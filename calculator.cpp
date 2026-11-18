
#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

bool ReadNumber(Number& result) {
    if (std::cin >> result) {
        return true;
    }

    std::cerr << "Error: Numeric operand expected" << std::endl;
    return false;
}

bool RunCalculatorCycle() {
    Number number;

    if (!ReadNumber(number)) {
        return false;
    }

    Number memory = 0;
    bool has_memory = false;

    std::string command;

    while (std::cin >> command) {
        if (command == "q") {
            return true;
        }

        if (command == "=") {
            std::cout << number << std::endl;
        } else if (command == "c") {
            number = 0;
        } else if (command == "s") {
            memory = number;
            has_memory = true;
        } else if (command == "l") {
            if (!has_memory) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            number = memory;
        } else if (command == "+" || command == "-" ||
                   command == "*" || command == "/" ||
                   command == "**" || command == ":") {

            Number operand;

            if (!ReadNumber(operand)) {
                return false;
            }

            if (command == "+") {
                number += operand;
            } else if (command == "-") {
                number -= operand;
            } else if (command == "*") {
                number *= operand;
            } else if (command == "/") {
                number /= operand;
            } else if (command == "**") {
                number = std::pow(number, operand);
            } else if (command == ":") {
                number = operand;
            }
                   } else {
                       std::cerr << "Error: Unknown token "
                                 << command << std::endl;
                       return false;
                   }
    }

    return false;
}
