#include <math.h>
#include "conveniences.h"

int viralAdvertising(int n) {
  int shared = 5;
  int liked = 2;
  int total = 2;

  while (--n >= 1) {
    shared = liked * 3;
    liked = floor(shared / 2);
    total += liked;
  }

  return total;
}

int main() { simplePrint(viralAdvertising(5)); }
