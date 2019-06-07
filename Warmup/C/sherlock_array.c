#include "conveniences.h"

char* balancedSums(int arr_count, int* arr) {
  int s = sum(arr, arr_count);
  int left = 0;
  for (int i = 0; i < arr_count; i++) {
    if (i != 0) {
      left += arr[i - 1];
    }
    int curr = s - arr[i];
    if (curr % 2 == 1) {
      continue;
    }
    if (curr / 2 == left) {
      return "YES";
    }
  }

  return "NO";
}

int main() {
  int arr[] = {1, 1, 4, 1, 1};
  int l = sizeof(arr) / sizeof(arr[0]);

  printf("%s\n", balancedSums(l, arr));
}
