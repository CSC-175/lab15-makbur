#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);
void clearInputStream();
void printResults(int, int);

// Function to clear the input stream in case of invalid input
void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*******************************************************************
* getInfo                                                          *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int& pickFrom, int& numPicks) {
    while (true) {
        cout << "How many balls (1-12) are in the pool to pick from? ";

        if (!(cin >> pickFrom) || pickFrom < 1 || pickFrom > 12) {
            clearInputStream();
            cout << "Input Error! There must be between 1 and 12 balls.\n";
            continue;
        }

        while (true) {
            cout << "How many balls (1-" << pickFrom << ") will be drawn? ";

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
    if (k > n) return 0;
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
* This function calculates and prints the probability and odds of  *
* winning based on the number of balls in the pool and the number  *
* of balls drawn. The format is aligned with the test expectations.*
*******************************************************************/
void printResults(int pickFrom, int numPicks) {
    // Calculate the number of ways to win (combinations)
    double successfulWays = computeWays(pickFrom, numPicks);

    // Total combinations from the selection of pickFrom
    double totalOutcomes = successfulWays;

    // Calculate probability and odds
    double probability = 1.0 / successfulWays;
    double odds = successfulWays;

    cout << fixed << setprecision(4);
    cout << "Probability of winning is " << probability << endl;
    cout << "Odds of winning are 1 in " << static_cast<int>(odds) << endl;
}

int main() {
    char repeat;
    do {
        int pickFrom, numPicks;

        // Get valid lottery numbers from the user
        getInfo(pickFrom, numPicks);

        // Print the calculated probability and odds
        printResults(pickFrom, numPicks);

        // Prompt for another calculation
        cout << "Would you like to calculate the probability of another scenario? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}