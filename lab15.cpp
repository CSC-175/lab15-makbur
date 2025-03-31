#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);
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
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is: n! / (k!(n - k)!)                       *
*******************************************************************/
double computeWays(int n, int k) {
    if (k == 0 || k == n) return 1;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*******************************************************************
* printResults                                                     *
* This function prints the probability and odds of winning based    *
* on the user's input.                                             *
*******************************************************************/
void printResults(int pickFrom, int numPicks) {
    // Compute the total number of possible outcomes (combinations)
    double successfulWays = computeWays(pickFrom, numPicks);
    double totalWays = computeWays(pickFrom, 0);  // This is simply the factorial of the pool size

    // Calculate probability of winning
    double probability = successfulWays / totalWays;

    // Calculate odds of winning
    double odds = (totalWays - successfulWays) / successfulWays;

    // Display results
    cout << fixed << setprecision(4);
    cout << "Probability of winning is " << probability << endl;
    cout << "Odds of winning are 1 in " << (1 / odds) << endl;
}

int main() {
    int pickFrom, numPicks;

    // Step 1: Get user input
    getInfo(pickFrom, numPicks);

    // Step 2: Compute and print results
    printResults(pickFrom, numPicks);

    return 0;
}
