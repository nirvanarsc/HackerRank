#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int lcm(int a, int b) { return abs(a * b) / gcd(a, b); }

int arrayApply(int* arr, int arr_length, int (*f)(int, int)) {
  if (arr_length < 2) {
    return arr[0];
  }
  int res = (*f)(arr[0], arr[1]);
  for (int i = 2; i < arr_length; i++) {
    res = (*f)(res, arr[i]);
  }
  return res;
}

int sumElements(int arr_length, int* arr) {
  int sum = 0;
  for (int i = 0; i < arr_length; i++) {
    sum += arr[i];
  }
  return sum;
}

void simplePrint(int d) { printf("%d\n", d); }

void simplePrintArray(int* arr, int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int* flatten(int s_rows, int s_columns, int** s) {
  int* result = (int*)malloc(s_rows * s_columns * sizeof(int));
  int currIndex = 0;
  for (int i = 0; i < s_rows; i++) {
    for (int j = 0; j < s_columns; j++) {
      result[currIndex++] = s[i][j];
    }
  }
  return result;
}
