#include <stdio.h>
#include <string.h>

int marsExploration(char* s) {
  int l = strlen(s);
  int i = 0;
  int res = 0;
  while (i < l) {
    if (s[i++] != 'S') {
      res++;
    }
    if (s[i++] != 'O') {
      res++;
    }
    if (s[i++] != 'S') {
      res++;
    }
  }
  return res;
}

int main() { printf("%d\n", marsExploration("SOSSOTSOSSOTSOSSOTSOSSOT")); }
