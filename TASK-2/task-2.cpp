#include <iostream>
#include <cstdlib>   // For rand() and srand() functions
#include <ctime>     // For time() function

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Variables to store user input and track the number of attempts
    int userGuess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        // Get user's guess
        cout << "Enter your guess (between 1 and 100): ";
        cin >> userGuess;

        // Increment the number of attempts
        attempts++;

        // Validate user input
        if (userGuess < 1 || userGuess > 100) {
            cout << "Invalid guess. Please enter a number between 1 and 100." << endl;
            continue;
        }

        // Provide feedback on the guess
        if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }

    } while (userGuess != secretNumber);

    return 0;
}
