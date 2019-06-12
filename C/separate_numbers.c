#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
  if (s[0] == '0') {
    return false;
  }
  return true;
}

bool checkNine(char* s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    if (s[i] != '9') {
      return false;
    }
  }
  return true;
}

char* get(char* s, int pos, int size) {
  char* sub = malloc(size);
  strncpy(sub, s + pos, size);
  return sub;
}

bool check(char* s, int l, int n) {
  int hadNine = 0;

  char* first = NULL;
  for (int i = 0; i < l; i += n) {
    if (first == NULL) {
      first = get(s, i, n);
    }
    if (checkNine(first)) {
      hadNine = 1;
      n++;
    }

    if (-hadNine + i + 2 * n > l) {
      if (-hadNine + i + n == l) {
        return true;
      }
      return false;
    }

    char* second = get(s, n + i - hadNine, n);

    if (!isValid(first) || !isValid(second) ||
        atoi(first) + 1 != atoi(second)) {
      return false;
    }

    first = second;
  }

  return true;
}

void separateNumbers(char* s) {
  int l = strlen(s);
  int max = l / 2;

  for (int i = 1; i <= max; i++) {
    if (check(s, l, i)) {
      printf("YES %s\n", get(s, 0, i));
      return;
    }
  }

  printf("NO\n");
}

int main() {
  separateNumbers("1234");
  separateNumbers("91011");
  separateNumbers("99100");
  separateNumbers("101103");
  separateNumbers("010203");
  separateNumbers("13");
  separateNumbers("9999899999100000");
}
