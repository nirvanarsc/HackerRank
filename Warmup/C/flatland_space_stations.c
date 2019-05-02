#include <stdbool.h>
#include "conveniences.h"

int flatlandSpaceStations(int n, int c_count, int* c) {
  int* map = calloc(n, sizeof(int));

  for (int i = 0; i < c_count; i++) {
    map[c[i]] = 1;
  }

  int maxIdx = max(c, c_count);
  int check = INT_MIN;
  int temp = 0;
  bool first = false;
  bool last = false;

  for (int i = 0; i < n; i++) {
    if (map[i] == 1) {
      if (i == maxIdx) {
        last = true;
      }
      if (!first) {
        first = true;
        if (temp > check) {
          check = temp;
        }
        temp = 0;
        continue;
      }
      temp = intCeil(temp, 2);
      if (temp > check) {
        check = temp;
      }
      temp = 0;
      continue;
    }
    temp++;
    if (last && i == n - 1) {
      if (temp > check) {
        check = temp;
      }
    }
  }

  return check;
}

int main() {
  int arr1[] = {68, 81, 46, 54, 30, 11, 19, 23, 22, 12,
                38, 91, 48, 75, 26, 86, 29, 83, 62};
  int arr1_length = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[] = {0};
  int arr2_length = sizeof(arr2) / sizeof(arr2[0]);

  simplePrint(flatlandSpaceStations(95, arr1_length, arr1));
  simplePrint(flatlandSpaceStations(100, arr2_length, arr2));
}
