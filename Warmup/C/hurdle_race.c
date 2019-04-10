#include "conveniences.h"

int hurdleRace(int k, int height_count, int* height) {
  int maxHeight = max(height, height_count);
  return k > maxHeight ? 0 : maxHeight - k;
}

int main() {
  int arr[] = {2, 5, 4, 5, 2};
  int arr_length = sizeof(arr) / sizeof(arr[0]);

  simplePrint(hurdleRace(4, arr_length, arr));
}
