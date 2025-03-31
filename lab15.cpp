#include <iostream>
#include <limits>
#include <iomanip> // For controlling output formatting
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);
void printResults(int, int); // Updated to print results with correct formatting
void clearInputStream();  // Utility function to clear input stream

// Function to clear the input stream in case of invalid input
void clearInputStream() {
    cin.clear();  // Clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
}

/*******************************************************************
* getInfo                                                          *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int& pickFrom, int& numPicks) {
    while (true) {
        cout << "How many balls (1-12) are in the pool to pick from? ";

        // Validate pickFrom to ensure it's an integer between 1 and 12
        if (!(cin >> pickFrom) || pickFrom < 1 || pickFrom > 12) {
            clearInputStream();
            cout << "Input Error! Please enter a number between 1 and 12.\n";
            continue;
        }

        while (true) {
            cout << "How many balls (1-" << pickFrom << ") will be drawn? ";

            // Validate numPicks to ensure it's an integer between 1 and pickFrom
            if (!(cin >> numPicks) || numPicks < 1 || numPicks > pickFrom) {
                clearInputStream();
                cout << "Input Error! Number of balls drawn must be between 1 and " << pickFrom << ".\n";
                continue;
            }

            break; // Break inner loop when numPicks is valid
        }

        break; // Break outer loop when both inputs are valid
    }
}

/*******************************************************************
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is: n! / (k!(n - k)!)                       *
*******************************************************************/
double computeWays(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*******************************************************************
* factorial                                                        *
* This function computes factorials recursively.                   *
*******************************************************************/
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/*******************************************************************
* printResults                                                     *
* This function calculates and prints the probability and odds of   *
* winning based on the number of balls in the pool and the number  *
* of balls drawn. The format is aligned with the test expectations. *
*******************************************************************/
void printResults(int pickFrom, int numPicks) {
    // Calculate the number of ways to win (combinations)
    double totalWays = computeWays(pickFrom, numPicks);

    // Calculate probability (winning ways / total possible outcomes)
    double totalOutcomes = computeWays(pickFrom, numPicks);
    double probability = totalWays / totalOutcomes;

    // Odds calculation (inverse of probability)
    double odds = 1.0 / probability - 1;

    // Ensure results match expected format
    cout << fixed << setprecision(4); // Fixed point notation with 4 decimals
    cout << "Probability of winning is " << probability << endl;
    cout << "Odds of winning are 1 in " << static_cast<int>(odds) << endl;
}
