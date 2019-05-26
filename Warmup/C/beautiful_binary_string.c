#include <stdio.h>
#include <string.h>

int beautifulBinaryString(char* b) {
  int l = strlen(b);
  int res = 0;
  int i = 0;

  while (i < l) {
    if (i + 2 >= l) {
      break;
    }
    if (b[i] == '0' && b[i + 1] == '1' && b[i + 2] == '0') {
      res++;
      i += 3;
    } else
      i++;
  }

  return res;
}

int main() {
  printf("%d\n", beautifulBinaryString("0100101010"));
  printf("%d\n", beautifulBinaryString("0101010"));
}
