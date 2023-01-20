#include <bits/stdc++.h>
#include <iostream>

int maxWeight;
int numItems;
int tempWeight;
int tempValue;

int compareValue(int compArray[], int compWeight[], int compVal[],
                 int iteratorJ, int iteratorI) {
  int wDiff = compArray[iteratorJ - compWeight[iteratorI - 1]];
  int vDiff = compVal[iteratorI - 1];
  return (wDiff + vDiff);
}

int knappy(int max, int passWeight[], int passVal[], int passSort) {
  int dynamicArray[max + 1]; // Declaring the DP array of size max + 1

  for (int i = 0; i < max + 1; i++) { // Resetting the DP array to 0
    dynamicArray[i] = 0;
  }

  for (int i = 1; i < passSort + 1; i++) {
    for (int j = max; j >= 0; j--) {
      if (passWeight[i - 1] <= j) { // If the weight is less than the max
        dynamicArray[j] =
            std::max(dynamicArray[j],
                     compareValue(dynamicArray, passWeight, passVal, j, i));
        // We compare the values and take the higher of the two.
      }
    }
  }
  return dynamicArray[max];
}

int main() {
  std::cin >> maxWeight;
  std::cin >> numItems;
  int value[numItems];
  int weight[numItems];
  for (int i = 0; i < numItems; i++) {
    std::cin >> tempWeight;
    weight[i] = tempWeight;
    std::cin >> tempValue;
    value[i] = tempValue;
  }

  int sortVal = sizeof(value) / sizeof(value[0]); // Sort by increasing value
  std::cout << knappy(maxWeight, weight, value, sortVal);
}