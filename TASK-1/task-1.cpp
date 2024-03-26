#include <iostream>

using namespace std;

class Calculator {
public:
    double add(double num1, double num2) {
        return num1 + num2;
    }

    double subtract(double num1, double num2) {
        return num1 - num2;
    }

    double multiply(double num1, double num2) {
        return num1 * num2;
    }

    double divide(double num1, double num2) {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "Error! Division by zero is not allowed." << endl;
            return 0.0;  // Return a default value
        }
    }
};

int main() {
    // Variables to store user input and result
    double num1, num2, result;
    char operation;

    // Create an instance of the Calculator class
    Calculator calculator;

    // Get user input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Get operation choice
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the operation and display the result
    switch (operation) {
        case '+':
            result = calculator.add(num1, num2);
            break;
        case '-':
            result = calculator.subtract(num1, num2);
            break;
        case '*':
            result = calculator.multiply(num1, num2);
            break;
        case '/':
            result = calculator.divide(num1, num2);
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            return 1;  // Return an error code
    }

    cout << "Result: " << result << endl;

    return 0;
}
