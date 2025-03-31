#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void getInfo(int& pickFrom, int& numPicks) {
    // Loop to ensure valid input for number of balls in the pool
    while (true) {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        if (!(cin >> pickFrom) || pickFrom < 1 || pickFrom > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input Error! Please enter a number between 1 and 12.\n";
            continue;
        }
        // Loop to ensure valid input for number of balls drawn
        cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
        if (!(cin >> numPicks) || numPicks < 1 || numPicks > pickFrom) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input Error! Number of balls drawn must be between 1 and " << pickFrom << ".\n";
            continue;
        }
        break;  // Exit loop once valid inputs are obtained
    }
}

double computeWays(int n, int k) {
    double result = 1;
    // Calculate the number of ways to choose k objects from n
    for (int i = 0; i < k; ++i) {
        result *= (n - i);  // Multiplying by remaining numbers
        result /= (i + 1);  // Dividing by the corresponding factorial part
    }
    return result;  // Return the computed result
}

void printResults(int pickFrom, int numPicks) {
    // Compute the total number of ways to pick the balls
    double totalWays = computeWays(pickFrom, numPicks);
    double totalOutcomes = computeWays(pickFrom, numPicks);

    // Calculate probability of winning
    double probability = totalWays / totalOutcomes;

    // Print results in the specified format with precision
    cout << fixed << setprecision(4);
    cout << "Probability of winning is " << probability << endl;
    cout << "Odds of winning are 1 in " << static_cast<int>(1.0 / probability) << endl;
}

void playGame() {
    int pickFrom = 0, numPicks = 0;
    char another = 'y';

    // Loop to allow user to play multiple times
    while (another == 'y' || another == 'Y') {
        getInfo(pickFrom, numPicks);  // Get user input
        printResults(pickFrom, numPicks);  // Print results for the current scenario
        // Ask if the user wants to play again
        cout << "\nWould you like to calculate the probability of another scenario? (y/n): ";
        cin >> another;
        cin.ignore();  // Clean up input buffer to handle 'y' or 'n'
    }
}

