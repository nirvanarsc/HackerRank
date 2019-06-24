#include "stdio.h"

char* gameOfStones(int n) {
  return (n % 7 == 0 || n % 7 == 1) ? "Second" : "First";
}

int main() {
  printf("%s\n", gameOfStones(1));
  printf("%s\n", gameOfStones(2));
  printf("%s\n", gameOfStones(3));
  printf("%s\n", gameOfStones(4));
  printf("%s\n", gameOfStones(5));
  printf("%s\n", gameOfStones(6));
  printf("%s\n", gameOfStones(7));
  printf("%s\n", gameOfStones(10));
}
