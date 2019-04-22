#include <stdio.h>
#include "conveniences.h"

void combinationUtil(int arr[], int data[], int start, int end, int index,
                     int r) {
  if (index == r) {
    for (int j = 0; j < r; j++) printf("%d ", data[j]);
    printf("\n");
    return;
  }

  for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
    data[index] = arr[i];
    combinationUtil(arr, data, i + 1, end, index + 1, r);
  }
}

void printCombination(int arr[], int n, int r) {
  int data[r];

  combinationUtil(arr, data, 0, n - 1, 0, r);
}

int* acmTeam(int topic_count, char** topic, int* result_count) {


    
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int r = 2;
  int n = sizeof(arr) / sizeof(arr[0]);
  printCombination(arr, n, r);
}
