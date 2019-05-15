#include <stdio.h>
#include <string.h>

char* hackerrankInString(char* s) {
  char* str = "hackerrank";
  int l = strlen(s);
  int l2 = strlen(str);
  int idx = 0;

  for (int i = 0; i < l; i++) {
    if (s[i] == str[idx]) {
      if (idx == l2 - 1) {
        return "YES";
      }
      idx++;
    }
  }

  return "NO";
}

int main() {
  printf("%s\n", hackerrankInString("hhaacckkekraraannk"));
  printf("%s\n",
         hackerrankInString("rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt"));
}
