#include <stdbool.h>
#include "conveniences.h"

int checkMap(int* map, int map_length, int i) {
  if (map[i] == 1) {
    return 0;
  }
  int left = i;
  int right = i;
  int distance1 = 0;
  int distance2 = 0;
  while (left >= 0) {
    if (--left == -1) {
      distance1 = INT_MAX;
      break;
    }
    distance1++;
    if (map[left] == 1) {
      break;
    }
  }
  while (right < map_length) {
    if (++right == map_length) {
      distance2 = INT_MAX;
      break;
    }
    distance2++;
    if (map[right] == 1) {
      break;
    }
  }

  printf("Checking %d - distance1 %d distance2 %d\n", i, distance1, distance2);
  return distance1 < distance2 ? distance1 : distance2;
}

int flatlandSpaceStations(int n, int c_count, int* c) {
  int* map = calloc(n, sizeof(int));
  int* res = malloc(n * sizeof(int));

  int minIdx = min(c, c_count);
  int maxIdx = max(c, c_count);

  for (int i = 0; i < c_count; i++) {
    map[c[i]] = 1;
  }

  for (int i = 0; i < n; i++) {
    res[i] = checkMap(map, n, i);
  }

  simplePrintArray(map, n);
  simplePrintArray(res, n);

  int check = INT_MIN;
  int temp = 0;
  bool last = false;

  for (int i = 0; i < n; i++) {
    if (i == minIdx) {
      if (temp > check) {
        check = temp;
      }
      temp = 0;
      continue;
    }
    if (i == maxIdx) {
      temp = intCeil(temp, 2);
      if (temp > check) {
        check = temp;
      }
      last = true;
      temp = 0;
      continue;
    }
    if (map[i] == 1) {
      temp = intCeil(temp, 2);
      if (temp > check) {
        check = temp;
      }
      temp = 0;
      continue;
    }
    temp++;
    if (last && i == n - 1) {
      if (temp > check) {
        check = temp;
      }
    }
  }
  simplePrint(check);
  return max(res, n);
}

int main() {
  int arr[] = {0};
  int arr_length = sizeof(arr) / sizeof(arr[0]);

  simplePrint(flatlandSpaceStations(10, arr_length, arr));
}