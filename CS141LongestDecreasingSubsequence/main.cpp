#include <bits/stdc++.h>
#include <iostream>

int numInputs;
int temp;

int LongestDecreasingSubsequence(int lds[], int size) {
  int findLDS[size];
  int i, j, k = 0;

  for (int i = 0; i < size; i++) { // The smallest LDS is 1 (unless no input)
    findLDS[i] = 1;
  }

  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (lds[i] < lds[j] && findLDS[i] <= findLDS[j]) {
        findLDS[i] = findLDS[j] + 1;
      }
    }
  }

  for (int i = 0; i < size; i++) {
    if (k < findLDS[i]) {
      k = findLDS[i];
    }
  }

  return k;
}

int main() {
  std::cin >> numInputs;
  int lds[numInputs];
  for (int i = 0; i < numInputs; i++) {
    std::cin >> temp;
    lds[i] = temp;
  }
  int size = sizeof(lds) / sizeof(lds[0]);
  std::cout << LongestDecreasingSubsequence(lds, size);
}