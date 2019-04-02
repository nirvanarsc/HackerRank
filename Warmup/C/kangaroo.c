#include <stdio.h>

char* kangaroo(int x1, int v1, int x2, int v2) {
  char* yes = "YES";
  char* no = "NO";

  if (v2 >= v1) {
    return no;
  }

  int distance = x2 - x1;
  int velocity_difference = v1 - v2;

  if (distance % velocity_difference != 0) {
    return no;
  }
  return yes;
}

int main() {
  printf("%s\n", kangaroo(0, 3, 4, 2));
  printf("%s\n", kangaroo(0, 2, 5, 3));
}
