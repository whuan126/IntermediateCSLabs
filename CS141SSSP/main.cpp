#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int verticesN, edgesM;
int start, destination;
int cityX, cityY, timeZ;
const int infinity = numeric_limits<int>::max();

typedef pair<int, int> intPair;

class adjList {
  int verticesN;
  list<pair<int, int>>* myList;
public:
  adjList(int verticesN);
  void setEdge(int cityX, int cityY, int timeZ);
  void findSP(int start);
};

adjList::adjList(int verticesN) {
  this->verticesN = verticesN;
  myList = new list<intPair>[verticesN];
}

void adjList::setEdge(int cityX, int cityY, int timeZ) {
  myList[cityX].push_back(make_pair(cityY, timeZ));
  myList[cityY].push_back(make_pair(cityX, timeZ));
}

int compareDis(int x, int y, int z) {
  if (y > x + z) {
    return true;
  }
  else {
    return false;
  }
  return false;
}

void adjList::findSP(int start) {
  priority_queue<intPair, vector<intPair>, greater<intPair>> PQ;
  vector<int> distance(verticesN, infinity);
  PQ.push(make_pair(0, start));
  distance[start] = 0;
  
  while (!PQ.empty()) {
    int cityX = PQ.top().second;
    PQ.pop();
    list<pair<int, int>>::iterator i;
    for (i = myList[cityX].begin(); i != myList[cityX].end(); i++) {
      int cityY = (*i).first;
      int timeZ = (*i).second;
      if (compareDis(distance[cityX], distance[cityY], timeZ)) {
        distance[cityY] = distance[cityX] + timeZ;
        PQ.push(make_pair(distance[cityY], cityY));
      }
    }
  }
  cout << distance[destination];
}

int main() {
  cin >> verticesN >> edgesM;
  cin >> start >> destination;

  adjList myGraph(verticesN);

  for (int i = 0; i < edgesM; i++) {
    cin >> cityX >> cityY >> timeZ;
    myGraph.setEdge(cityX, cityY, timeZ);
  }

  myGraph.findSP(start);
  
  return 0;
}