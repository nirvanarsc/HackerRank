#include "conveniences.h"

int utopianTree(int n) {
  if (n <= 0) {
    return 1;
  }
  int height = 1;

  while (1) {
    height *= 2;
    if (--n == 0) break;
    height += 1;
    if (--n == 0) break;
  }
  return height;
}

int main() { simplePrint(utopianTree(4)); }
