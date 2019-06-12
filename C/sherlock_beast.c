#include <stdio.h>

void check(int n, int modulo) {
  int fives = n - modulo;
  for (int i = 0; i < fives; i++) {
    printf("%d", 5);
  }
  for (int i = 0; i < n - fives; i++) {
    printf("%d", 3);
  }
  printf("\n");
}

void decentNumber(int n) {
  if (n < 3) {
    printf("%d\n", -1);
    return;
  }
  if (n % 3 == 0) {
    for (int i = 0; i < n; i++) {
      printf("%d", 5);
    }
    printf("\n");
    return;
  }
  if (n % 3 == 1) {
    if (n < 10) {
      printf("%d\n", -1);
      return;
    }
    check(n, 10);
    return;
  }
  if (n % 3 == 2) {
    check(n, 5);
    return;
  }
}

int main() {
  decentNumber(1);
  decentNumber(3);
  decentNumber(5);
  decentNumber(11);
  decentNumber(13);
}
