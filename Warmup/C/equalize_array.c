#include <limits.h>
#include "conveniences.h"

int equalizeArray(int arr_count, int* arr) {
  int* map = calloc(100, sizeof(int));

  for (int i = 0; i < arr_count; i++) {
    map[arr[i]]++;
  }

  return arr_count - max(map, 100);
}

int main() {
  int arr[] = {32, 32, 37, 72, 72, 96, 12, 32, 67, 37, 57, 18,
               57, 78, 29, 34, 67, 16, 34, 78, 72, 33, 96, 16,
               37, 32, 87, 43, 29, 16, 48, 49, 29, 37, 32};
  int len = sizeof(arr) / sizeof(arr[0]);
  simplePrint(len);
  simplePrint(equalizeArray(len, arr));
}
