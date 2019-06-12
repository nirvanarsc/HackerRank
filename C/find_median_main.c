#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, k, sum = 0;
  scanf("%d", &size);
  int *map = calloc(20001, sizeof(int));
  for (int i = 0; i < size; i++) {
    scanf("%d", &k);
    map[k + 10000]++;
  }

  for (int i = 0; i < 20001; i++) {
    sum += map[i];
    if (sum > size / 2) {
      printf("%d\n", i - 10000);
      break;
    }
  }
  return 0;
}
