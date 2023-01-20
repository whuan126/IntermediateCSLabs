#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int takenSquares;
string inputSpace;
int input2;
int numInputs;
string occupiedSpace;
string startingPos, finalPos;
int knightPos[2], targetPos[2];
int chessBoard[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
vector<int> arrayVector;

void printArray() {
  for (int p = 0; p < numInputs; p++) {
    if (arrayVector.at(p) != -1) {
      cout << "Board " << p + 1 << ": " << arrayVector.at(p) << " moves"
           << endl;
    } else {
      cout << "Board " << p + 1 << ": not reachable" << endl;
    }
  }
}

bool validMove(int x, int y) {
  if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
    return true;
  }
  return false;
}

struct banana {
  int row, col;
  int distance;
  banana() {}
  banana(int row, int col, int distance)
      : row(row), col(col), distance(distance) {}
};

void clearBoard() {
  for (int row = 0; row < 8; row++) {
    for (int column = 0; column < 8; column++) {
      chessBoard[row][column] = 0;
    }
  }
}

int minSteps(int knightPos[], int targetPos[]) {

  if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) {
    return 0;
  }

  int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
  int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

  queue<banana> juice;
  juice.push(banana(knightPos[0], knightPos[1], 0));

  banana yummy;
  int x, y;
  bool visit[8][8];
  // initializing the blocked nodes
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
      if (chessBoard[i][j] == 1) {
        visit[i][j] = true;
      } else {
        visit[i][j] = false;
      }
    }
  }

  visit[knightPos[0]][knightPos[1]] = true;

  while (!juice.empty()) {
    yummy = juice.front();
    juice.pop();

    if ((yummy.row == targetPos[0] && yummy.col == targetPos[1])) {
      return yummy.distance;
    }

    for (int i = 0; i <= 7; i++) {
      x = yummy.row + dx[i];
      y = yummy.col + dy[i];
      if ((validMove(x, y) && !visit[x][y])) {
        visit[x][y] = true;
        juice.push(banana(x, y, yummy.distance + 1));
      }
    }
  }
  return -1;
}

void flagSpaces(int takenSquares) { // input taken squares
  if (takenSquares != 0 && takenSquares > 0) {
    for (int i = 0; i < takenSquares; i++) {
      cin >> inputSpace;
      if (inputSpace[1] == '1') {
        input2 = 0;
      }
      if (inputSpace[1] == '2') {
        input2 = 1;
      }
      if (inputSpace[1] == '3') {
        input2 = 2;
      }
      if (inputSpace[1] == '4') {
        input2 = 3;
      }
      if (inputSpace[1] == '5') {
        input2 = 4;
      }
      if (inputSpace[1] == '6') {
        input2 = 5;
      }
      if (inputSpace[1] == '7') {
        input2 = 6;
      }
      if (inputSpace[1] == '8') {
        input2 = 7;
      }
      if (inputSpace[0] == 'a') {
        chessBoard[0][input2] = 1;
      }
      if (inputSpace[0] == 'b') {
        chessBoard[1][input2] = 1;
      }
      if (inputSpace[0] == 'c') {
        chessBoard[2][input2] = 1;
      }
      if (inputSpace[0] == 'd') {
        chessBoard[3][input2] = 1;
      }
      if (inputSpace[0] == 'e') {
        chessBoard[4][input2] = 1;
      }
      if (inputSpace[0] == 'f') {
        chessBoard[5][input2] = 1;
      }
      if (inputSpace[0] == 'g') {
        chessBoard[6][input2] = 1;
      }
      if (inputSpace[0] == 'h') {
        chessBoard[7][input2] = 1;
      }
    }
  }

  cin >> startingPos >> finalPos; // get starting and final positions
  if (startingPos != " ") {
    if (startingPos[0] == 'a') {
      knightPos[0] = 0;
    }
    if (startingPos[0] == 'b') {
      knightPos[0] = 1;
    }
    if (startingPos[0] == 'c') {
      knightPos[0] = 2;
    }
    if (startingPos[0] == 'd') {
      knightPos[0] = 3;
    }
    if (startingPos[0] == 'e') {
      knightPos[0] = 4;
    }
    if (startingPos[0] == 'f') {
      knightPos[0] = 5;
    }
    if (startingPos[0] == 'g') {
      knightPos[0] = 6;
    }
    if (startingPos[0] == 'h') {
      knightPos[0] = 7;
    }

    if (startingPos[1] == '1') {
      knightPos[1] = 0;
    }
    if (startingPos[1] == '2') {
      knightPos[1] = 1;
    }
    if (startingPos[1] == '3') {
      knightPos[1] = 2;
    }
    if (startingPos[1] == '4') {
      knightPos[1] = 3;
    }
    if (startingPos[1] == '5') {
      knightPos[1] = 4;
    }
    if (startingPos[1] == '6') {
      knightPos[1] = 5;
    }
    if (startingPos[1] == '7') {
      knightPos[1] = 6;
    }
    if (startingPos[1] == '8') {
      knightPos[1] = 7;
    }
  }
  if (finalPos != " ") {
    if (finalPos[0] == 'a') {
      targetPos[0] = 0;
    }
    if (finalPos[0] == 'b') {
      targetPos[0] = 1;
    }
    if (finalPos[0] == 'c') {
      targetPos[0] = 2;
    }
    if (finalPos[0] == 'd') {
      targetPos[0] = 3;
    }
    if (finalPos[0] == 'e') {
      targetPos[0] = 4;
    }
    if (finalPos[0] == 'f') {
      targetPos[0] = 5;
    }
    if (finalPos[0] == 'g') {
      targetPos[0] = 6;
    }
    if (finalPos[0] == 'h') {
      targetPos[0] = 7;
    }

    if (finalPos[1] == '1') {
      targetPos[1] = 0;
    }
    if (finalPos[1] == '2') {
      targetPos[1] = 1;
    }
    if (finalPos[1] == '3') {
      targetPos[1] = 2;
    }
    if (finalPos[1] == '4') {
      targetPos[1] = 3;
    }
    if (finalPos[1] == '5') {
      targetPos[1] = 4;
    }
    if (finalPos[1] == '6') {
      targetPos[1] = 5;
    }
    if (finalPos[1] == '7') {
      targetPos[1] = 6;
    }
    if (finalPos[1] == '8') {
      targetPos[1] = 7;
    }
  }
  
  arrayVector.push_back(minSteps(knightPos, targetPos));
  cin >> takenSquares;
  if (takenSquares != -1) {
    numInputs++;
    clearBoard();
    flagSpaces(takenSquares);
  } else {
    printArray();
  }
}

int main() {
  cin >> takenSquares;
  if (takenSquares != -1) {
    numInputs++;
    flagSpaces(takenSquares);
  }
  return 0;
}