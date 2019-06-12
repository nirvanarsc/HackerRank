#include <stdbool.h>
#include "conveniences.h"
#include "merge_sort.h"

int findMinDistance(int* arr, int arr_count, int* atIndex) {
  int min = INT_MAX;
  for (int i = 0; i < arr_count - 1; i++) {
    if (abs(arr[i] - arr[i + 1]) < min) {
      *atIndex = i;
      min = abs(arr[i] - arr[i + 1]);
    }
  }
  return min;
}

int* closestNumbers(int arr_count, int* arr, int* result_count) {
  mergeSort(arr, 0, arr_count - 1);
  int atIndex = 0;
  int min = findMinDistance(arr, arr_count, &atIndex);

  int curr_size = 2;
  int* res = malloc(curr_size * sizeof(int));
  int currIdx = 0;
  res[currIdx++] = arr[atIndex];
  res[currIdx++] = arr[atIndex + 1];

  int nextIndex = atIndex + 1;
  while (nextIndex < arr_count - 1) {
    if (abs(arr[nextIndex] - arr[nextIndex + 1]) == min) {
      curr_size += 2;
      int* temp = malloc(curr_size * sizeof(int));
      memcpy(temp, res, (curr_size - 2) * sizeof(int));
      temp[currIdx++] = arr[nextIndex];
      temp[currIdx++] = arr[nextIndex + 1];
      free(res);
      res = temp;
    }
    nextIndex++;
  }
  *result_count = curr_size;
  return res;
}

int main() {
  int arr1[] = {-20, -3916237, -357920,  -3620601, 7374819, -7330761,
                30,  6246457,  -6461594, 266854,   -520,    -470};
  int arr2[] = {-5, 15, 25, 71, 63};

  int arr_size1 = sizeof(arr1) / sizeof(arr1[0]);
  int arr_size2 = sizeof(arr2) / sizeof(arr2[0]);

  int result_count1 = 0;
  int result_count2 = 0;

  simplePrintArray(closestNumbers(arr_size1, arr1, &result_count1),
                   result_count1);
  simplePrintArray(closestNumbers(arr_size2, arr2, &result_count2),
                   result_count2);
}
