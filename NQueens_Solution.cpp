#include <iostream>

using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if (q[c] == q[i] or (c - i) == abs(q[c] - q[i])) {
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
    int n = 12;
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}
