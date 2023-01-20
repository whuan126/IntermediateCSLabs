#include <bits/stdc++.h>
#include <iostream>

int numInputs;
int temp;

int LongestUnimodelSubsequence(int lds[], int size) {
  int findLDS[size];
  int backwards[size];

  for (int i = 0; i < size; i++) { // The smallest LDS is 1 (unless no input)
    findLDS[i] = 1;
    backwards[i] = 1;
  }

  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (lds[i] > lds[j] && findLDS[i] <= findLDS[j]) {
        findLDS[i] = findLDS[j] + 1;
      }
    }
  }

  for (int i = size - 1; i >= 0; i--) {
    for (int j = size - 1; j > i; j--) {
      if (lds[i] > lds[j] && backwards[i] <= backwards[j]) {
        backwards[i] = backwards[j] + 1;
      }
    }
  }

  int sum = findLDS[0] + backwards[0];
  for (int i = 1; i < size; i++) {
    if ((findLDS[i] + backwards[i]) > sum) {
      sum = findLDS[i] + backwards[i];
    }
  }

  return sum - 1;
}

int main() {
  std::cin >> numInputs;
  int lds[numInputs];
  for (int i = 0; i < numInputs; i++) {
    std::cin >> temp;
    lds[i] = temp;
  }
  std::cout << LongestUnimodelSubsequence(lds, numInputs);
}