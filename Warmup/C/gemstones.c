#include <stdbool.h>
#include "conveniences.h"

bool contains(char* arr, char c) {
  int l = strlen(arr);
  for (int i = 0; i < l; i++) {
    if (arr[i] == c) {
      return true;
    }
  }
  return false;
}

int gemstones(int arr_count, char** arr) {
  int* map = calloc(26, sizeof(int));

  char* first = arr[0];
  int l = strlen(first);

  int res = 0;

  for (int i = 0; i < l; i++) {
    if (map[first[i] - 'a'] == 1) {
      continue;
    }
    map[first[i] - 'a'] = 1;
    for (int j = 1; j < arr_count; j++) {
      if (!contains(arr[j], first[i])) {
        goto a;
      }
    }
    res++;
  a:
    continue;
  }

  return res;
}

int main() {
  int arr_count = 4;
  char** arr = malloc(arr_count * sizeof(char*));
  arr[0] = "basdfj";
  arr[1] = "asdlkjfdjsa";
  arr[2] = "bnafvfnsd";
  arr[3] = "oafhdlasd";
  simplePrint(gemstones(arr_count, arr));
}
