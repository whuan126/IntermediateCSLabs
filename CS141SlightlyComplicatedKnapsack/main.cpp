#include <bits/stdc++.h>
#include <iostream>

int maxWeight;
int numItems;
int maxSelect;
int tempWeight;
int tempValue;

int compareValue(int compArray[], int compWeight[], int compVal[],
                 int iteratorJ, int iteratorI) {
  int wDiff = compArray[iteratorJ - compWeight[iteratorI - 1]];
  int vDiff = compVal[iteratorI - 1];
  return (wDiff + vDiff);
}

int knappy(int max, int passWeight[], int passVal[], int passItems,
           int passSelect) {
  int dynamicArray[max + 1]; // Declaring the DP array of size max + 1

  for (int i = 0; i < max + 1; i++) { // Resetting the DP array to 0
    dynamicArray[i] = 0;
  }

  for (int i = 1; i < passItems + 1; i++) {
    for (int k = passSelect; k > 0; k--) {
      for (int j = max; j >= 0; j--) {
        if (passWeight[i - 1] <= j) { // If the weight is less than the max
          dynamicArray[j] =
              std::max(dynamicArray[j],
                       compareValue(dynamicArray, passWeight, passVal, j, i));
          // We compare the values and take the higher of the two.
        }
      }
    }
  }
  return dynamicArray[max];
}

int main() {
  std::cin >> maxWeight;
  std::cin >> numItems; //numStudents
  std::cin >> maxSelect; //maxSeats
  int value[numItems];
  int weight[numItems];
  for (int i = 0; i < numItems; i++) {
    std::cin >> tempWeight;
    weight[i] = tempWeight;
    std::cin >> tempValue;
    value[i] = tempValue;
  }

  std::cout << knappy(maxWeight, weight, value, numItems, maxSelect);
}