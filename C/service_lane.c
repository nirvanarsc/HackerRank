#include <string.h>
#include "conveniences.h"

int* serviceLane(int n, int* width, int cases_rows, int cases_columns,
                 int** cases, int* result_count) {
  *result_count = cases_rows;
  int* res = calloc(cases_rows, sizeof(int));
  for (int i = 0; i < *result_count; i++) {
    int length = cases[i][1] - cases[i][0] + 1;
    int* temp = malloc(length * sizeof(int));
    memcpy(temp, width + cases[i][0], length * sizeof(int));
    res[i] = min(temp, length);
    free(temp);
  }
  return res;
}

int main() {
  int res_length = 0;
  int n = 100;
  int width[] = {1, 3, 2, 1, 2, 3, 1, 3, 1, 3, 2, 2, 1, 2, 3, 1, 1, 2, 1, 2,
                 2, 3, 1, 2, 3, 1, 1, 1, 3, 2, 2, 3, 2, 3, 2, 1, 1, 3, 1, 1,
                 1, 2, 3, 1, 3, 3, 2, 2, 1, 3, 3, 1, 3, 1, 2, 2, 3, 2, 1, 2,
                 2, 2, 2, 3, 3, 3, 1, 3, 3, 1, 1, 1, 1, 3, 1, 3, 1, 3, 2, 1,
                 3, 3, 1, 2, 3, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int cases_rows = 100;
  int cases_columns = 2;
  int arr[] = {44, 92, 72, 93, 13, 85, 32, 92, 25, 45, 32, 34, 91, 97, 83, 84,
               53, 56, 88, 97, 25, 28, 39, 65, 48, 94, 8,  36, 23, 96, 94, 97,
               21, 70, 96, 99, 61, 94, 40, 61, 74, 87, 21, 85, 33, 70, 50, 62,
               77, 82, 4,  79, 63, 98, 65, 96, 63, 83, 96, 99, 91, 96, 54, 85,
               56, 77, 44, 50, 74, 78, 1,  34, 57, 69, 17, 64, 23, 35, 73, 94,
               3,  52, 3,  84, 18, 43, 78, 94, 43, 75, 68, 88, 63, 94, 46, 82,
               68, 81, 37, 96, 74, 77, 91, 96, 59, 66, 17, 78, 73, 97, 83, 97,
               65, 67, 41, 43, 54, 82, 65, 99, 91, 99, 31, 37, 51, 55, 76, 97,
               66, 80, 61, 77, 52, 93, 70, 83, 60, 90, 91, 93, 77, 96, 8,  10,
               59, 71, 25, 65, 63, 89, 9,  38, 21, 72, 10, 83, 14, 24, 88, 91,
               97, 98, 20, 46, 2,  19, 59, 96, 75, 89, 92, 97, 24, 70, 93, 94,
               47, 90, 93, 98, 9,  86, 65, 74, 42, 80, 0,  58, 59, 84, 37, 56,
               39, 89, 7,  98, 44, 65, 2,  81};
  int** cases = malloc(cases_rows * sizeof(int*));
  for (int i = 0; i < cases_rows; i++) {
    cases[i] = malloc(cases_columns * sizeof(int));
  }
  populate2dArray(cases, cases_rows, cases_columns, arr);

  int* res =
      serviceLane(n, width, cases_rows, cases_columns, cases, &res_length);
  simplePrintArray(res, res_length);
}
