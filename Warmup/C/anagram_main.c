#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int test;
  scanf("%d", &test);

  for (int x = 0; x < test; x++) {
    int res = 0;
    char *str = malloc(10000);
    scanf("%s", str);
    int l = strlen(str);

    if (l % 2 == 1) {
      res = -1;
    } else {
      int *lmap = calloc(26, sizeof(int));
      int *rmap = calloc(26, sizeof(int));
      for (int i = 0, j = l / 2; i < l / 2; i++, j++) {
        lmap[str[i] - 'a']++;
        rmap[str[j] - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        res += abs(lmap[i] - rmap[i]);
      }
      res = res / 2;
    }
    printf("%d\n", res);
  }

  return 0;
}
