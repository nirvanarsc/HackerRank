#include "conveniences.h"

int jumpingOnClouds(int c_count, int* c) {
  int curr = 0;
  int step = 0;
  while (curr < c_count - 1) {
    if (c[curr] == 0 && c[curr + 1] == 0 && c[curr + 2] == 0) {
      curr += 2;
      step++;
      continue;
    }
    if (c[curr] == 0 && c[curr + 1] == 1 && c[curr + 2] == 0) {
      curr += 2;
      step++;
      continue;
    }
    curr++;
    step++;
  }
  return step;
}

int main() {
  int arr[] = {0, 0, 0, 1, 0, 0};
  int len = sizeof(arr) / sizeof(arr[0]);
  int arr2[] = {0, 0, 1, 0, 0, 1, 0};
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  simplePrint(jumpingOnClouds(len, arr));
  simplePrint(jumpingOnClouds(len2, arr2));
}
