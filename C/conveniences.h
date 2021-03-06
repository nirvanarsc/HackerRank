#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  int min = INT_MAX;
  for (int i = 0; i < arr_length; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

int max(int* arr, int arr_length) {
  int max = INT_MIN;
  for (int i = 0; i < arr_length; i++) {
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

void simplePrintCharArray(char* arr) {
  for (int i = 0; i < (int)strlen(arr); i++) {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

void simplePrint2dArray(int** arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    simplePrintArray(arr[i], cols);
  }
}

void simplePrint2dCharArray(char** arr, int rows) {
  for (int i = 0; i < rows; i++) {
    simplePrintCharArray(arr[i]);
  }
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

int getIntLength(int number) { return log10(number) + 1; }

int getLongLength(long number) { return log10(number) + 1; }

int* toArray(int number, int* arr_length) {
  int n = getIntLength(number);
  *arr_length = n;
  int* numberArray = calloc(n, sizeof(int));
  for (int i = 0; i < n; ++i, number /= 10) {
    numberArray[i] = number % 10;
  }
  return numberArray;
}

int* toReverseArray(int number, int* arr_length) {
  int n = getIntLength(number);
  *arr_length = n;
  int* numberArray = calloc(n, sizeof(int));
  for (int i = n - 1; i >= 0; --i, number /= 10) {
    numberArray[i] = number % 10;
  }
  return numberArray;
}

int binomialCoeff(int n, int k) {
  if (k == 0 || k == n) return 1;

  return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void populate2dArray(int** matrix, int rows, int cols, int* arr) {
  int index = 0;
  for (int r = 0; r < rows; r++) {
    for (int j = 0; j < cols; j++) {
      matrix[r][j] = arr[index++];
    }
  }
}

void populate2dCharArray(char** matrix, int rows, int cols, char* arr) {
  int index = 0;
  for (int r = 0; r < rows; r++) {
    for (int j = 0; j < cols; j++) {
      matrix[r][j] = arr[index++];
    }
  }
}

int intCeil(int x, int y) { return x / y + (x % y != 0); }

long prevPow2(long num) { return pow(2, floor(log(num) / log(2))); }
