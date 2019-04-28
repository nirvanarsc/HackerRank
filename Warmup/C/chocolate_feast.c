#include "conveniences.h"

int wrapperCount(int bought, int m) {
  int ex = bought % m;
  int new = bought / m;
  if (new + ex >= m) {
    new += wrapperCount(new + ex, m);
  }
  return new;
}

int chocolateFeast(int n, int c, int m) {
  int bought = n / c;

  return bought + wrapperCount(bought, m);
}

int main() {
  simplePrint(chocolateFeast(2216, 8, 35));
  simplePrint(chocolateFeast(77879, 179, 31082));
}
