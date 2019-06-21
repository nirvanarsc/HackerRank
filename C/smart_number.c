#include <math.h>
#include <stdbool.h>
#include <stdio.h>

char* is_smart_number(int num) {
  int val = (int)sqrt(num);
  if (val * val == num) return "YES";
  return "NO";
}

int main() {
  printf("%s\n", is_smart_number(1));
  printf("%s\n", is_smart_number(2));
  printf("%s\n", is_smart_number(7));
  printf("%s\n", is_smart_number(169));
}
