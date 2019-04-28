#include "conveniences.h"

int workbook(int n, int k, int arr_count, int* arr) {
  int res = 0;
  int curr_page = 1;
  for (int i = 0; i < arr_count; i++) {
    for (int j = 1; j <= arr[i]; j++) {
      if (curr_page == j) {
        res++;
      }
      if (j % k == 0) {
        curr_page++;
      }
    }
    if (arr[i] % k != 0) {
      curr_page++;
    }
  }

  return res;
}

int main() {
  int arr[] = {3, 8, 15, 11, 14, 1, 9, 2, 24, 31};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  simplePrint(workbook(arr_length, 5, arr_length, arr));
}
