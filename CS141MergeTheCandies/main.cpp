#include <bits/stdc++.h>
#include <iostream>

int numBags;
int initialSize;
std::vector<int> candies;
int currentSum;

int returnStack(int x, int y) { return x + y; }

int main() {
  std::cin >> numBags;
  for (int i = 0; i < numBags; i++) {
    std::cin >> initialSize;
    candies.push_back(initialSize);
  }

  while (candies.size() != 1) {
    std::sort(candies.begin(), candies.end());
    currentSum += 2 * (candies.at(0) + candies.at(1));
    candies.push_back(returnStack(candies.at(0), candies.at(1)));
    candies.erase(candies.begin());
    candies.erase(candies.begin());
  }

  std::cout << currentSum;
}