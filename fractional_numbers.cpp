#include <iostream>
#include <string>

int main() {
    std::string integerPart, fractionalPart;

    // Get input from user
    std::cout << "Enter the integer part: ";
    std::cin >> integerPart;

    std::cout << "Enter the fractional part: ";
    std::cin >> fractionalPart;

    // Combine integer and fractional parts
    std::string combinedNumber = integerPart + "." + fractionalPart;

    // Convert the combined string to a double
    double result = std::stod(combinedNumber);

    // Print the result
    std::cout << "The combined number is: " << result << std::endl;

    return 0;
}
