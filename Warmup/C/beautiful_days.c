#include <stdbool.h>
#include "conveniences.h"

bool check(int i, int k) {
  int arr_length;
  int reverse = 0;
  int* arr = toReverseArray(i, &arr_length);
  for (int i = 0; i < arr_length; i++) {
    reverse += arr[i] * pow(10, i);
  }

  return (i - reverse) % k == 0;
}

int beautifulDays(int i, int j, int k) {
  int beautiful_days = 0;

  while (i <= j) {
    if (check(i, k)) {
      beautiful_days++;
    }
    i++;
  }

  return beautiful_days;
}

int main() { simplePrint(beautifulDays(20, 23, 6)); }
