#include <stdlib.h>
#include "conveniences.h"

int sockMerchant(int arr_count, int* arr) {
  int* map = calloc(100, sizeof(int));

  int pairs = 0;

  for (int i = 0; i < arr_count; i++) {
    if (map[arr[i]] == 1) {
      pairs++;
      map[arr[i]] = 0;
    } else {
      map[arr[i]]++;
    }
  }
  return pairs;
}

int main() {
  int arr[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  simplePrint(sockMerchant(arr_length, arr));
}
