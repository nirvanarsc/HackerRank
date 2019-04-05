#include "conveniences.h"

int getMoneySpent(int keyboards_count, int* keyboards, int drives_count,
                  int* drives, int b) {
  int moneySpent = 0;

  for (int i = 0; i < keyboards_count; i++) {
    for (int j = 0; j < drives_count; j++) {
      int curr = keyboards[i] + drives[j];
      if (moneySpent < curr && 0 <= b - curr) {
        moneySpent = curr;
      }
    }
  }
  if (moneySpent == 0) {
    return -1;
  }

  return b - moneySpent < 0 ? -1 : moneySpent;
}

int main() {
  int keyboards1[] = {3, 1};
  int keyboards1_length = sizeof(keyboards1) / sizeof(keyboards1[0]);
  int keyboards2[] = {4};
  int keyboards2_length = sizeof(keyboards2) / sizeof(keyboards2[0]);
  int drives1[] = {5, 2, 8};
  int drives1_length = sizeof(drives1) / sizeof(drives1[0]);
  int drives2[] = {5};
  int drives2_length = sizeof(drives2) / sizeof(drives2[0]);
  simplePrint(
      getMoneySpent(keyboards1_length, keyboards1, drives1_length, drives1, 10));
  simplePrint(
      getMoneySpent(keyboards2_length, keyboards2, drives2_length, drives2, 5));
}
