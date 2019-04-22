#include <stdio.h>
#include <string.h>

long repeatedString(char *s, long n) {
  long total = 0;
  int curr = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] == 'a') {
      curr++;
    }
  }

  total = (n / len) * curr;

  if (n % len == 0) {
    return total;
  }

  int check = n % len;

  for (int i = 0; i < check; i++) {
    if (s[i] == 'a') {
      total++;
    }
  }

  return total;
}

int main() {
  char *s1 = "aba";
  char *s2 = "a";
  printf("%ld\n", repeatedString(s1, 10));
  printf("%ld\n", repeatedString(s2, 1000000000000));
}
