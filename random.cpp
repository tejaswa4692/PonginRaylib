#include <iostream>

int main() {
    // Declare three integer variables: firstNumber, secondNumber, and sum
    int firstNumber, secondNumber, sum;

    std::cout << "Enter the first number: ";
    // Use std::cin to read the first integer from the user
    std::cin >> firstNumber;

    std::cout << "Enter the second number: ";
    // Use std::cin to read the second integer from the user
    std::cin >> secondNumber;

    // Calculate the sum of the two numbers
    sum = firstNumber + secondNumber;

    // Print the result to the console using std::cout
    std::cout << "The sum of " << firstNumber << " and " << secondNumber << " is: " << sum << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
