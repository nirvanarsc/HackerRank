#include <math.h>
#include "conveniences.h"

int squares(int a, int b) {
  double low = ceil(sqrt(a));
  double high = floor(sqrt(b));

  return high - low + 1;
}

int main() {
  simplePrint(squares(3, 9));
  simplePrint(squares(100, 1000));
}
