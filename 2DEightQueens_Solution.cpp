#include <iostream>

using namespace std;

int main() {
  int numSolutions = 0;
  int q[8][8] = {};
  int r = 0, c = 0;
  q[r][c] = 1;

  nextCol: c++;
  if (c == 8) {
    goto print;
  }
  r = -1;

  nextRow: r++;
  if (r == 8) {
    goto backtrack;
  }
  for (int i = 0; i < c; i++) {
    if (q[r][i] == 1)
      goto nextRow;
  }

  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if (q[r - i][c - i] == 1)
      goto nextRow;
  }

  for (int i = 1; r + i < 8 && c - i >= 0; i++) {
    if (q[r + i][c - i] == 1)
      goto nextRow;
  }

  q[r][c] = 1;
  goto nextCol;

  backtrack: c--;
  if (c == -1) {
    return 0;
  }
  r = 0;
  while (q[r][c] != 1) {
    r++;
  }
  q[r][c] = 0;
  goto nextRow;

  print:
    cout << "Solution #" << ++numSolutions << ":\n";
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      cout << q[r][c] << " ";
    }
    cout << endl;
  }
  goto backtrack;

  return 0;
}