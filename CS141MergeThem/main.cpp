#include <cmath>
#include <iostream>

int numStudents;
int tempScore;
int candies;
// int studentArray[] = {};

void mergeThem(int studentArray[], int begin, int mid, int end) {
  int sub1 = mid - begin + 1;
  int sub2 = end - mid;
  int pineapple[sub1];
  int pizza[sub2];

  for (int i = 0; i < sub1; i++) {
    pineapple[i] = studentArray[begin + i];
  }
  for (int j = 0; j < sub2; j++) {
    pizza[j] = studentArray[mid + 1 + j];
  }

  int foo = 0;
  int bar = 0;
  int k = begin;

  while (foo < sub1 && bar < sub2) {
    if (pineapple[foo] <= pizza[bar]) {
      studentArray[k] = pineapple[foo];
      foo++;
    } else {
      studentArray[k] = pizza[bar];
      bar++;
    }
    k++;
  }

  while (foo < sub1) {
    studentArray[k] = pineapple[foo];
    foo++;
    k++;
  }

  while (bar < sub2) {
    studentArray[k] = pizza[bar];
    bar++;
    k++;
  }

  candies += abs(studentArray[begin] - studentArray[end]);
}

void mergeSort(int studentArray[], int first, int last) {
  if (first < last) {
    int middle = first + (last - first) / 2;
    mergeSort(studentArray, first, middle);
    mergeSort(studentArray, middle + 1, last);

    mergeThem(studentArray, first, middle, last);
  }
}

int main() {
  std::cin >> numStudents;
  int studentArray[numStudents];
  for (int i = 0; i < numStudents; i++) {
    std::cin >> tempScore;
    studentArray[i] = tempScore;
  }

  mergeSort(studentArray, 0, numStudents - 1);

  std::cout << candies;

  return 0;
}