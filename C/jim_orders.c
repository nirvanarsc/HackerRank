#include "conveniences.h"
#include "merge_sort.h"

int* jimOrders(int orders_rows, int orders_columns, int** orders,
               int* result_count) {
  int* sums = malloc(orders_rows * sizeof(int));
  int* copy = malloc(orders_rows * sizeof(int));
  int* map = calloc(2000000, sizeof(int));

  for (int i = 0; i < orders_rows; i++) {
    sums[i] = orders[i][0] + orders[i][1];
    copy[i] = sums[i];
  }

  mergeSort(sums, 0, orders_rows - 1);

  for (int i = 0; i < orders_rows; i++) {
    if (map[copy[i]] == 0) {
      map[copy[i]] = i + 1;
    } else {
      // hashmap collision => lazy linked list
      map[copy[i] + 1] = i + 1;
    }
  }

  int prev = sums[0];
  for (int i = 0; i < orders_rows; i++) {
    if (sums[i] == prev && i != 0) {
      prev = sums[i];
      sums[i] = map[sums[i] + 1];
    } else {
      prev = sums[i];
      sums[i] = map[sums[i]];
    }
  }

  *result_count = orders_rows;
  return sums;
}

int main() {
  int rows = 25;
  int cols = 2;
  int** orders = malloc(25 * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    orders[i] = malloc(cols * sizeof(int));
  }
  int arr[] = {
      122470, 725261, 193218, 693005, 355776, 603340, 830347, 284246, 974815,
      823134, 251206, 572501, 55509,  927152, 299590, 651593, 222305, 641645,
      984018, 463771, 494787, 286091, 217190, 833029, 820867, 380896, 744986,
      630663, 875880, 667,    449199, 520904, 924615, 511326, 862614, 890277,
      959638, 373599, 685864, 923011, 922324, 407528, 157354, 943714, 380643,
      714960, 269853, 608576, 290422, 195768,
  };
  populate2dArray(orders, rows, cols, arr);

  int l = 0;
  int* res = jimOrders(rows, cols, orders, &l);
  simplePrintArray(res, l);
}
