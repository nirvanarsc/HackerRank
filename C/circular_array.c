#include "conveniences.h"

int* circularArrayRotation(int a_count, int* a, int k, int queries_count,
                           int* queries, int* result_count) {
  *result_count = queries_count;
  int* res = malloc(queries_count * sizeof(int));
  for (int i = 0; i < queries_count; i++) {
    res[i] = a[(a_count + queries[i] - k % a_count) % a_count];
  }

  return res;
}
int main() {
  int asd = 0;
  int queries[] = {47, 10, 12, 13, 6,  29, 22, 17, 7,  3,  30, 45, 1,  21, 50,
                   17, 25, 42, 5,  6,  47, 2,  24, 1,  6,  14, 24, 43, 7,  2,
                   35, 3,  13, 22, 16, 19, 0,  12, 10, 32, 41, 14, 1,  42, 35,
                   0,  9,  34, 17, 14, 15, 38, 17, 13, 40, 48, 27, 38, 41, 8,
                   14, 25, 11, 27, 47, 2,  20, 22, 39, 4,  28, 29, 43, 29, 21,
                   1,  4,  4,  10, 46, 43, 50, 33, 34, 12, 47, 32, 13, 8,  47,
                   22, 23, 21, 33, 24, 43, 35, 19, 39, 24};
  int arr[] = {39356, 87674, 16667, 54260, 43958, 70429, 53682, 6169,  87496,
               66190, 90286, 4912,  44792, 65142, 36183, 43856, 77633, 38902,
               1407,  88185, 80399, 72940, 97555, 23941, 96271, 49288, 27021,
               32032, 75662, 69161, 33581, 15017, 56835, 66599, 69277, 17144,
               37027, 39310, 23312, 24523, 5499,  13597, 45786, 66642, 95090,
               98320, 26849, 72722, 37221, 28255, 60906};
  int q_length = sizeof(queries) / sizeof(queries[0]);
  int length = sizeof(arr) / sizeof(arr[0]);

  int* res = circularArrayRotation(length, arr, 51, q_length, queries, &asd);

  simplePrintArray(res, asd);
}
