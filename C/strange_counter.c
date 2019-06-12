#include "conveniences.h"

long calcN(long iter) {
  if (iter == 0) {
    return 3;
  }
  return 2 * (calcN(--iter));
}

long findIter(long t, long* offset) {
  long iter = floor(log((t + 2) / 3) / log(2));
  *offset = t - 3 * pow(2, iter) + 2;

  return iter;
}

long strangeCounter(long t) {
  long offset = 0;
  long iter = findIter(t, &offset);

  return calcN(iter) - offset;
}

int main() {
  printf("%ld\n", strangeCounter(1000000000000));
  printf("%ld\n", strangeCounter(100));
}
