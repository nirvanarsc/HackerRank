#include "conveniences.h"

int findDigits(int n) {
  int res = 0;
  int len = 0;
  int* arr = toArray(n, &len);
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] == 0) {
      continue;
    }
    if (n % arr[i] == 0) {
      res++;
    }
  }
  return res;
}

int main() {
  simplePrint(findDigits(111));
  simplePrint(findDigits(1012));
}
