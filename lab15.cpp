#include <iostream>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

/*******************************************************************
* getInfo                                                          *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int& pickFrom, int& numPicks) {
    while (true) {
        // Get the number of balls to pick from
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> pickFrom;

        // Validate the number of balls to pick from
        if (pickFrom < 1 || pickFrom > 12) {
            cout << "Input Error! There must be between 1 and 12 balls.\n";
            continue;
        }

        // Get the number of balls to draw
        cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
        cin >> numPicks;

        // Validate the number of balls to draw
        if (numPicks < 1 || numPicks > pickFrom) {
            cout << "Input Error! Number of picks must be between 1 and " << pickFrom << ".\n";
            continue;
        }

        // If validation passes, break out of the loop
        break;
    }
}

/*******************************************************************
* computeWays                                                       *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is: k!(n - k)! / n!                         *
*******************************************************************/
double computeWays(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*******************************************************************
* factorial                                                         *
* This function computes factorials recursively.                   *
*******************************************************************/
double factorial(int n) {
    // Base case: 0! = 1 and 1! = 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int pickFrom, // The number of numbers to pick from
        numPicks; // The number of numbers to select
    double ways; // The number of different possible
                 // ways to pick the set of numbers
    char again;

    do {
        getInfo(pickFrom, numPicks);
        ways = computeWays(pickFrom, numPicks);
        cout.setf(ios::fixed);
        cout.precision(4);
        cout << "\nProbability of winning is " << ways;
        cout << "\nOdds of winning are 1 in " << int(1/ways);
        cout << "\n\nWould you like to calculate the probability of another scenario? (y/n): ";
        cin >> again;
    } while (again == 'y' or again == 'Y');

    return 0;
}
