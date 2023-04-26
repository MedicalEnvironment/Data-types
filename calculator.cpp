#include <iostream>
#include <string>
#include <sstream>

int main() {
    double number1, number2;
    char operation;
    std::string buffer;

    std::cout << "Enter the operation in the format: <number-1><action><number-2> (no spaces): ";
    std::getline(std::cin, buffer);

    std::stringstream buffer_stream(buffer);
    buffer_stream >> number1 >> operation >> number2;

    double result;

    switch (operation) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 == 0) {
                std::cerr << "Error: Division by zero!" << std::endl;
                return 1;
            }
            result = number1 / number2;
            break;
        default:
            std::cerr << "Error: Invalid operation!" << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
