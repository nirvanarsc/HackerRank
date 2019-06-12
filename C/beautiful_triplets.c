#include "conveniences.h"

int beautifulTriplets(int d, int arr_count, int* arr) {
  int res = 0;
  for (int i = 0; i < arr_count; i++) {
    for (int j = 0; j < arr_count; j++) {
      if (arr[j] == arr[i] - d) {
        for (int k = 0; k < arr_count; k++) {
          if (arr[k] == arr[i] + d) {
            res++;
            break;
          }
        }
      }
    }
  }
  return res;
}

int main() {
  int arr[] = {1, 6, 7, 7, 8, 10, 12, 13, 14, 19};
  int arr_length = sizeof(arr) / sizeof(arr[0]);

  simplePrint(beautifulTriplets(3, arr_length, arr));
}
