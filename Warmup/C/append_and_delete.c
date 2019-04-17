#include <string.h>
#include "conveniences.h"

char* readline();

// helloworld
// helloboy
char* appendAndDelete(char* s, char* t, int k) {
  int s_length = strlen(s);
  int t_length = strlen(t);
  int min_actions;
  int max_common = s_length > t_length ? t_length : s_length;
  int i = 0;

  while (i < max_common) {
    if (s[i] != t[i]) {
      break;
    }
    i++;
  }
  
  
  


  char* yes = "Yes";
  char* no = "No";

  return no;
}

int main() {}
