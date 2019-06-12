#include <string.h>
#include "conveniences.h"

char* appendAndDelete(char* s, char* t, int k) {
  char* yes = "Yes";
  char* no = "No";
  int s_length = strlen(s);
  int t_length = strlen(t);
  int max_common = s_length > t_length ? t_length : s_length;
  int i = 0;

  while (i < max_common) {
    if (s[i] != t[i]) {
      break;
    }
    i++;
  }

  int diff = (s_length - i) + (t_length - i);

  if (k < diff) {
    return no;
  } else if (diff % 2 == k % 2) {
    return yes;
  } else if (s_length + t_length - k < 0) {
    return yes;
  }
  return no;
}

int main() {
  char* s = "abcdef";
  char* t = "fedcba";
  printf("%s\n", appendAndDelete(s, t, 11));
  printf("%s\n", appendAndDelete(s, t, 12));
}
