#include <iostream>

using namespace std;

int main() {
  int numSolutions = 0;
  int q[8] = {
    -1
  };
  int c = 0;

  q[0] = 0;

  nextCol: c++;
  if (c == 8) {
    goto print;
  }
  q[c] = -1;

  nextRow: q[c]++;
  if (q[c] == 8) {
    goto backtrack;
  }
  for (int i = 0; i < c; i++) {
    if (q[i] == q[c] or (c - i) == abs(q[c] - q[i])) {
      goto nextRow;
    }
  }
  goto nextCol;

  backtrack: c--;
  if (c == -1) {
    return 0;
  }

  goto nextRow;

  print:
    cout << "Solution #" << ++numSolutions << ":\n";
  cout << "Solution Array: [";
  for (int i = 0; i < c; i++) {
    if (i < c - 1) {
      cout << q[i] << ",";
    } else {
      cout << q[i];
    }
  }
  cout << "]\n";
  cout << "Chessboard Below:" << endl;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      if (q[j] == i) {
        cout << 1 << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
  goto backtrack;

  return 0;
}