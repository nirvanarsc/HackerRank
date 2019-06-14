#include <stdio.h>

int lonelyinteger(int a_count, int* a) {
  int res = a[0];
  for (int i = 1; i < a_count; i++) {
      res ^= a[i];
  }
  return res;
}

int main() {
    int arr[] = {0,1,2,3,4,5,4,3,2,1};
    int l = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", lonelyinteger(l, arr));
}
