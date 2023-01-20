#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numFirstYears;
vector<string> Gryff; vector<string> Huff; vector<string> Raven; vector<string> Slyth;
string studentName, houseName;

int main() {
  cin >> numFirstYears;
  for (int i = 0; i < numFirstYears; i++) {
    cin >> studentName >> houseName;
    if (houseName == "Gryffindor" || houseName == "Hufflepuff" || houseName == "Ravenclaw" || houseName == "Slytherin") {
      if (houseName == "Gryffindor") {
        Gryff.push_back(studentName);
      }
      if (houseName == "Hufflepuff") {
        Huff.push_back(studentName);
      }
      if (houseName == "Ravenclaw") {
        Raven.push_back(studentName);
      }
      if (houseName == "Slytherin") {
        Slyth.push_back(studentName);
      }
    }
  }
  cout << "Gryffindor" << endl;
  sort(Gryff.begin(), Gryff.end());
  for (string x: Gryff) {
    cout << x << endl;
  }
  cout << "Hufflepuff" << endl;
  sort(Huff.begin(), Huff.end());
  for (string x: Huff) {
    cout << x << endl;
  }
  cout << "Ravenclaw" << endl;
  sort(Raven.begin(), Raven.end());
  for (string x: Raven) {
    cout << x << endl;
  }
  cout << "Slytherin" << endl;
  sort(Slyth.begin(), Slyth.end());
  for (string x: Slyth) {
    cout << x << endl;
  }
}