#include "conveniences.h"

int pageCount(int n, int p) {
  return p <= n / 2 ? p / 2 : n % 2 == 0 ? (n - p + 1) / 2 : (n - p) / 2;
}

int main() {
  simplePrint(pageCount(1000, 996));
  simplePrint(pageCount(1000, 997));
  simplePrint(pageCount(1000, 998));
  simplePrint(pageCount(1000, 999));
  simplePrint(pageCount(1000, 1000));
  printf("\n");
  simplePrint(pageCount(1001, 997));
  simplePrint(pageCount(1001, 998));
  simplePrint(pageCount(1001, 999));
  simplePrint(pageCount(1001, 1000));
  simplePrint(pageCount(1001, 1001));
}
