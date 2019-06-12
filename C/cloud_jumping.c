#include "conveniences.h"

int jumpingOnClouds(int c_count, int* c, int k) {
  int i = 0;
  int energy = 100;

  while (1) {
    int step = (i * k) % c_count;
    if (step == 0 && i != 0) {
      break;
    }
    if (c[step] == 1) {
      energy -= 2;
    }
    energy--;
    i++;
  }
  return energy;
}

int main() {
  int c[] = {1, 1, 1, 0, 1, 1, 0, 0, 0, 0};
  int c_length = sizeof(c) / sizeof(c[0]);

  simplePrint(jumpingOnClouds(c_length, c, 3));
}
