#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* happyLadybugs(char* b) {
  char* yes = "YES";
  char* no = "NO";
  int length = strlen(b);
  int* map = calloc(32, sizeof(int));

  for (int i = 0; i < length; i++) {
    map[b[i] - 'A']++;
  }

  for (int i = 0; i < 30; i++) {
    if (map[i] == 1) {
      return no;
    }
  }

  char prev = b[0];
  int c = 1;
  bool check = false;
  for (int i = 1; i < length; i++) {
    if (b[i] == prev) {
      c++;
      continue;
    }
    if (c == 1) {
      check = true;
      break;
    }
    prev = b[i];
    c = 1;
  }

  if (check && map[30] == 0) {
    return no;
  }

  return yes;
}

int main() {
  printf("%s\n", happyLadybugs("RBY_YBR"));
  printf("%s\n", happyLadybugs("X_Y__X"));
  printf("%s\n", happyLadybugs("B_RRBR"));
  printf("%s\n", happyLadybugs("__"));
  printf("%s\n", happyLadybugs("RBRB"));
  printf("%s\n", happyLadybugs("RRRR"));
  printf("%s\n", happyLadybugs("BBB"));
  printf("%s\n", happyLadybugs("BBB_"));
  printf("%s\n", happyLadybugs("IIIAA"));
}
