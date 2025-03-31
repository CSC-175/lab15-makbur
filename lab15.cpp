#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void getInfo(int& pickFrom, int& numPicks) {
    while (true) {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        if (!(cin >> pickFrom) || pickFrom < 1 || pickFrom > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input Error! Please enter a number between 1 and 12.\n";
            continue;
        }
        cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
        if (!(cin >> numPicks) || numPicks < 1 || numPicks > pickFrom) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input Error! Number of balls drawn must be between 1 and " << pickFrom << ".\n";
            continue;
        }
        break;
    }
}

double computeWays(int n, int k) {
    double result = 1;
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

void printResults(int pickFrom, int numPicks) {
    double totalWays = computeWays(pickFrom, numPicks);
    double totalOutcomes = computeWays(pickFrom, numPicks);
    double probability = totalWays / totalOutcomes;

    cout << fixed << setprecision(4);
    cout << "Probability of winning is " << probability << endl;
    cout << "Odds of winning are 1 in " << static_cast<int>(1.0 / probability) << endl;
}
