#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char* numbers = "0123456789";
char* lower_case = "abcdefghijklmnopqrstuvwxyz";
char* upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* special_characters = "!@#$%^&*()-+";

bool containedIn(char c, char* arr) {
  int l = strlen(arr);
  for (int i = 0; i < l; i++) {
    if (arr[i] == c) {
      return true;
    }
  }
  return false;
}

int minimumNumber(int n, char* password) {
  bool num = false;
  bool lc = false;
  bool uc = false;
  bool sc = false;

  for (int i = 0; i < n; i++) {
    if (!num && containedIn(password[i], numbers)) {
      num = true;
      continue;
    }
    if (!lc && containedIn(password[i], lower_case)) {
      lc = true;
      continue;
    }
    if (!uc && containedIn(password[i], upper_case)) {
      uc = true;
      continue;
    }
    if (!sc && containedIn(password[i], special_characters)) {
      sc = true;
      continue;
    }
  }

  int actions = 0;
  if (!num) {
    actions++;
  }
  if (!lc) {
    actions++;
  }
  if (!uc) {
    actions++;
  }
  if (!sc) {
    actions++;
  }
  if (n < 6) {
    return 6 - n > actions ? 6 - n : actions;
  }

  return actions;
}

int main() {
  char* pw = "06HL";

  printf("%d\n", minimumNumber(4, pw));
}
