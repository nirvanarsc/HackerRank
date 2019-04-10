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

int sum(int* arr, int arr_length) {
  int sum = 0;
  for (int i = 0; i < arr_length; i++) {
    sum += arr[i];
  }
  return sum;
}

int min(int* arr, int arr_length) {
  int min = arr[0];
  for (int i = 1; i < arr_length; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

int max(int* arr, int arr_length) {
  int max = arr[0];
  for (int i = 1; i < arr_length; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
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

int* removeDuplicates(int* arr, int arr_length, int* new_length) {
  int res = 0;
  int curr = 1;
  int i = 0;

  while (i < arr_length) {
    if (curr > arr_length) {
      res = i;
      for (int j = i; j < arr_length; j++) {
        arr[j] = -1;
      }
      break;
    }
    if (arr[i] == arr[curr]) {
      curr++;
      continue;
    }
    arr[i + 1] = arr[curr];
    i++;
  }
  *new_length = res;
  return arr;
}

int countUniques(int* arr, int arr_length) {
  if (arr_length <= 1) {
    return arr_length;
  }
  int counter = 1;
  int prev = arr[0];
  for (int i = 1; i < arr_length; i++) {
    if (arr[i] == prev) {
      continue;
    }
    counter++;
    prev = arr[i];
  }

  return counter;
}
