#include "conveniences.h"

int howManyGames(int p, int d, int m, int s) {
  int games = 0;
  while (1) {
    int price = p - games * d > m ? p - games * d : m;
    s -= price;
    if (s < 0) {
      break;
    }
    games++;
  }
  return games;
}

int main() {
  simplePrint(howManyGames(20, 3, 6, 80));
  simplePrint(howManyGames(20, 3, 6, 85));
  simplePrint(howManyGames(16, 2, 1, 9981));
}
