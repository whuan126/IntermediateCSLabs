#include <bits/stdc++.h>
#include <iostream>

int numDepartments;
int minSupporters;
int comparisons;
int temp1;
std::vector<int> numFaculty;

int main() {
  std::cin >> numDepartments;
  for (int i = 0; i < numDepartments; i++) {
    std::cin >> temp1;
    numFaculty.push_back(temp1);
  }
  sort(numFaculty.begin(), numFaculty.end());

  comparisons = 1 + (numDepartments / 2);

  for (int i = 0; i < comparisons; i++) {
    minSupporters += 1 + (numFaculty[i] / 2);
  }

  std::cout << minSupporters;
}