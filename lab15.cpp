#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);
void clearInputStream(); // Utility function to clear input stream

// Function to clear any residual input in the stream
void clearInputStream()
{
    cin.clear(); // Clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
}

/*******************************************************************
* getInfo                                                          *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int& pickFrom, int& numPicks) {
    while (true) {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        if (!(cin >> pickFrom)) {
            clearInputStream();
            cout << "Input Error!\n";
            continue;
        }

        if (pickFrom < 1 || pickFrom > 12) {
            cout << "Input Error! There must be between 1 and 12 balls.\n";
            continue;
        }

        while (true) {
            cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
            if (!(cin >> numPicks)) {
                clearInputStream();
                cout << "Input Error!\n";
                continue;
            }

            if (numPicks < 1 || numPicks > pickFrom) {
                cout << "Input Error!\n";
                continue;
            }

            break; // Break the inner loop if numPicks is valid
        }

        break; // Break the outer loop if all inputs are valid
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
