#include <cmath>
#include <iostream>

using namespace std;

int jigsawPieces, roundsPlayed; // first line of input
int p1, p2, p3, p4;
int team1Hp, team2Hp;
int t1Product, t2Product;
int currentRound = 1;

int main() {

  cin >> jigsawPieces;
  cin >> roundsPlayed;
  team1Hp = jigsawPieces;
  team2Hp = jigsawPieces;

  while (currentRound <= roundsPlayed) {
    cin >> p1 >> p2 >> p3 >> p4;
    if (1 <= p1 && p1 <= 6 && 1 <= p2 && p2 <= 6 && 1 <= p3 && p3 <= 6 &&
        1 <= p4 && p4 <= 6) {
      t1Product = p1 * p2;
      t2Product = p3 * p4;
      team2Hp -= t1Product;
      team1Hp -= t2Product;
      if (team2Hp <= 0 || team1Hp <= 0) {
        if (team2Hp <= 0 && team1Hp <= 0) {
          cout << "It's a tie at round " << currentRound << "!";
          break;
        }
        if (team1Hp <= 0) {
          cout << "Team 2 wins at round " << currentRound << "!";
          break;
        }
        if (team2Hp <= 0) {
          cout << "Team 1 wins at round " << currentRound << "!";
          break;
        }
      }
      if (currentRound == roundsPlayed) {
        cout << "Oh no!";
      }
      currentRound += 1;
    }
  }
}