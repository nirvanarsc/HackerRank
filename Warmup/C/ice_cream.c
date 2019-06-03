#include <stdio.h>
#include <stdlib.h>

int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
  int* map = calloc(100000, sizeof(int));
  *result_count = 2;
  int* res = malloc(*result_count * sizeof(int));

  for (int i = 0; i < arr_count; i++) {
    map[arr[i]] = i;
  }
  for (int i = 0; i < arr_count; i++) {
    if (map[m - arr[i]] == 0) {
      continue;
    }
    if (map[m - arr[i]] != i) {
      res[0] = i + 1;
      res[1] = map[m - arr[i]] + 1;
      break;
    }
  }

  return res;
}

int main() {
  int arr[] = {230, 863, 916, 585, 981, 404, 316, 785, 88,  12,  70,  435, 384,
               778, 887, 755, 740, 337, 86,  92,  325, 422, 815, 650, 920, 125,
               277, 336, 221, 847, 168, 23,  677, 61,  400, 136, 874, 363, 394,
               199, 863, 997, 794, 587, 124, 321, 212, 957, 764, 173, 314, 422,
               927, 783, 930, 282, 306, 506, 44,  926, 691, 568, 68,  730, 933,
               737, 531, 180, 414, 751, 28,  546, 60,  371, 493, 370, 527, 387,
               43,  541, 13,  457, 328, 227, 652, 365, 430, 803, 59,  858, 538,
               427, 583, 368, 375, 173, 809, 896, 370, 789};
  int l = sizeof(arr) / sizeof(arr[0]);
  int a = 0;
  int* res = icecreamParlor(542, l, arr, &a);
  printf("%d %d\n", res[0], res[1]);
}
