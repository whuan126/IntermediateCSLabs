#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int numDevices, possConnections;
int X, Y, Z;
const int infinity = numeric_limits<int>::max();

typedef pair<int, int> intPair;

class adjList {
  int numDevices;
  list<pair<int, int>> *myList;

public:
  adjList(int numDevices);
  void setEdge(int X, int Y, int Z);
  void findMST();
};

adjList::adjList(int numDevices) {
  this->numDevices = numDevices;
  myList = new list<intPair>[numDevices];
}

void adjList::setEdge(int X, int Y, int Z) {
  myList[X].push_back(make_pair(Y, Z));
  myList[Y].push_back(make_pair(X, Z));
}

void adjList::findMST() {
  priority_queue<intPair, vector<intPair>, greater<intPair>> PQ;
  vector<int> distance(numDevices, infinity);
  vector<int> storeMST(numDevices, -1);
  vector<bool> isVisited(numDevices, false);

  PQ.push(make_pair(0, 0));
  distance[0] = 0;

  while (!PQ.empty()) {
    int X = PQ.top().second;
    PQ.pop();
    if (isVisited[X] == true) {
      continue;
    }
    isVisited[X] = true;
    list<pair<int, int>>::iterator i;
    for (i = myList[X].begin(); i != myList[X].end(); i++) {
      int Y = (*i).first;
      int Z = (*i).second;
      if (isVisited[Y] == false && distance[Y] > Z) {
        distance[Y] = Z;
        PQ.push(make_pair(distance[Y], Y));
        storeMST[Y] = X;
      }
    }
  }
  int MSTCost = 0;
  for (int i = 0; i < numDevices; i++) {
    MSTCost += distance[i];
  }
  cout << MSTCost;
}

int main() {
  cin >> numDevices >> possConnections;

  adjList myGraph(numDevices);

  for (int i = 0; i < possConnections; i++) {
    cin >> X >> Y >> Z;
    myGraph.setEdge(X, Y, Z);
  }

  myGraph.findMST();

  return 0;
}