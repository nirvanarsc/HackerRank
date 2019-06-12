#include <stdbool.h>
#include "conveniences.h"

bool contains(char* s, char c, int l) {
  for (int i = 0; i < l; i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

char* getUniques(char* s, int l) {
  char* u = calloc(30, sizeof(char));
  int index = 0;
  u[index] = s[index];
  for (int i = 1; i < l; i++) {
    if (!contains(u, s[i], l)) {
      u[++index] = s[i];
    }
  }
  return u;
}

int remove_and_check(char* s, char a, char b, int l) {
  int counter = 0;
  char prev;
  for (int i = 0; i < l; i++) {
    if (s[i] == a || s[i] == b) {
      if (counter == 0) {
        prev = s[i];
        counter++;
        continue;
      }
      if (s[i] == prev) {
        counter = 0;
        break;
      }
      counter++;
      prev = s[i];
    }
  }
  return counter;
}

int alternate(char* s) {
  int l = strlen(s);
  char* uniques = getUniques(s, l);
  int u_length = strlen(uniques);
  int max = 0;
  for (int i = 0; i < u_length; i++) {
    for (int j = i + 1; j < u_length; j++) {
      int curr = remove_and_check(s, uniques[i], uniques[j], l);
      if (curr > max) {
        max = curr;
      }
    }
  }

  return max;
}

int main() {
  simplePrint(alternate("abaacdabd"));
  simplePrint(alternate("beabeefeab"));
  simplePrint(alternate("asvkugfiugsalddlasguifgukvsa"));
}
