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

void print(int q[]) {
  cout << "[";
  for (int i = 0; i < 8; i++) {
    if (i < 7) {
      cout << q[i] << ",";
    } else {
      cout << q[i];
    }
  }
  cout << "]";
  cout << endl;
}

void board(int q[]) {
  cout << "Chessboard Below:\n";
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == q[j]) {
        cout << "1 ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

int main() {
  int q[8] = {};
  int c = 0;
  int numSolutions = 0;

  while (c >= 0) {
    c++;

    if (c == 8) {
      cout << "Solution #" << ++numSolutions << "\n" << "Solution Array: ";
      print(q);
      board(q);
    }
    q[c] = -1;

    while (c >= 0) {
      q[c]++;

      if (q[c] == 8) {
        q[c] = -1;
        c--;
      } else if (ok(q, c)) {
        break;
      }
    }
  }
  return 0;
}