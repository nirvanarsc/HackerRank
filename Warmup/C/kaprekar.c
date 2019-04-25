#include <stdbool.h>
#include "conveniences.h"

bool checkKaprekar(int num) {
  long num_square = pow(num, 2);
  int num_length = getIntLength(num);
  int square_length = getLongLength(num_square);
  int r_length = num_length;
  int l_length = square_length - r_length;

  char *r = malloc(r_length * sizeof(char));
  char *l = malloc(l_length * sizeof(char));
  char *str = malloc(square_length * sizeof(char));

  sprintf(str, "%ld", num_square);

  for (int i = 0, i1 = 0, i2 = 0; i < square_length; i++) {
    if (i1 < l_length) {
      l[i1++] = str[i];
    } else {
      r[i2++] = str[i];
    }
  }

  return atoi(l) + atoi(r) == num;
}

void kaprekarNumbers(int p, int q) {
  bool none = false;
  char *invalid_range = "INVALID RANGE";
  for (int i = p; i <= q; i++) {
    if (checkKaprekar(i)) {
      if (!none) {
        none = true;
      }
      printf("%d ", i);
    }
  }
  if (!none) {
    printf("%s\n", invalid_range);
  } else
    printf("\n");
}

int main() { kaprekarNumbers(1, 99999); }
