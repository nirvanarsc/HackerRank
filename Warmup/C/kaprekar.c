#include <stdbool.h>
#include "conveniences.h"

int main() {
  int a = 100;
  int a_length = getIntLength(a);

  int a_square = a * a;
  int square_length = getIntLength(a_square);

  int r_length = a_length;
  char r[r_length * sizeof(char)];
  int l_length = square_length - r_length;
  char l[l_length * sizeof(char)];
  simplePrint(r_length);
  simplePrint(l_length);

  simplePrint(a * a);

  char str[square_length * sizeof(char)];
  sprintf(str, "%d", a * a);

  for (int i = 0, j = l_length; i < l_length; i++, j++) {
    l[i] = str[i];
    r[i] = str[j];
  }

  printf("Decimal value = %s\n", l);
  printf("Decimal value = %s\n", r);

  int g1 = atoi(l);
  int g2 = atoi(r);
  simplePrint(g1);
  simplePrint(g2);
}
