#include <bits/stdc++.h>
#include <iostream>

int aLength, bLength;
int aSequence, bSequence;
int temp;

int compareThree(int uno, int dos, int tres) {
  return std::min(std::min(uno, dos), tres);
}

int WED(int X[], int Y[], int i, int j) {

  int DP[i + 1][j + 1];
  for (int p = 0; p < i + 1; p++) {
    for (int q = 0; q < j + 1; q++) {
      DP[p][q] = 0;
    }
  }

  for (int p = 0; p < i + 1; p++) {
    for (int q = 0; q < j + 1; q++) {
      if (p == 0 && q == 0) {
        DP[p][q] = 0;
      } else if (q == 0) {
        DP[p][q] = DP[p - 1][q] + X[p - 1];
      } else if (p == 0) {
        DP[p][q] = DP[p][q - 1] + Y[q - 1];
      } else if (X[p - 1] == Y[q - 1]) {
        DP[p][q] = DP[p - 1][q - 1];
      } else {
        int ins = DP[p][q - 1] + Y[q - 1];
        int del = DP[p - 1][q] + X[p - 1];
        int edit = DP[p - 1][q - 1] + std::abs(X[p - 1] - Y[q - 1]);
        DP[p][q] = compareThree(ins, del, edit);
      }
    }
  }
  return DP[i][j];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> aLength >> bLength;
  int stringA[aLength];
  int stringB[bLength];
  for (int i = 0; i < aLength; i++) {
    std::cin >> temp;
    stringA[i] = temp;
  }
  for (int i = 0; i < bLength; i++) {
    std::cin >> temp;
    stringB[i] = temp;
  }
  std::cout << WED(stringA, stringB, aLength, bLength);
}