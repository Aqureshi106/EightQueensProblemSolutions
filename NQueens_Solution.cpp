#include <iostream>

using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if (q[c] == q[i] or(c - i) == abs(q[c] - q[i])) {
            return false;
        }
    }
    return true;
}

int nqueens(int n) {
    int * q = new int[n];
    int c = 0;
    int numSolutions = 0;
    q[0] = 0;

    while (c >= 0) {
        c++;
        if (c == n) {
            ++numSolutions;
            c--;
        } else {
            q[c] = -1;
        }
        while (c >= 0) {
            q[c]++;
            if (q[c] == n) {
                q[c] = -1;
                c--;
            } else if (ok(q, c)) {
                break;
            }
        }
    }
    delete[] q;
    return numSolutions;
}

int main() {
    int n = 0;
    cout << "Please input a positive integer to find the amount of solutions of n number of queens on n by n chessboard: ";
    cin >> n;
    while (n < 0) {
        if (n < 0) {
        cout << "Incorrect input! Try again: ";
        cin >> n;
        }
    }
    cout << "There are " << nqueens(n) << " solutions to the " << n << " queens problem.\n";
    return 0;
}
