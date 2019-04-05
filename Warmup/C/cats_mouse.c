#include <stdio.h>
#include <stdlib.h>

char* catAndMouse(int x, int y, int z) {
  char* catA = "Cat A";
  char* catB = "Cat B";
  char* mouse = "Mouse C";

  if (abs(z - x) == abs(z - y)) {
    return mouse;
  }

  return abs(z - x) < abs(z - y) ? catA : catB;
}

int main() {
  printf("%s\n", catAndMouse(1, 3, 2));
  printf("%s\n", catAndMouse(1, 2, 3));
  printf("%s\n", catAndMouse(0, 5, 2));
}
