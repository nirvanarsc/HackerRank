#include <stdbool.h>
#include "conveniences.h"

int *convertToMap(char *s, int l) {
  char prev;
  int repeated = 1;
  int *map = calloc(10000000, sizeof(int));

  for (int i = 0; i < l; i++) {
    if (s[i] == prev) {
      repeated++;
    } else {
      prev = s[i];
      repeated = 1;
    }
    int x = (s[i] - '`') * repeated;
    if (map[x] == 0) {
      map[x] = 1;
    }
  }

  return map;
}

char **weightedUniformStrings(char *s, int queries_count, int *queries,
                              int *result_count) {
  *result_count = queries_count;
  int l = strlen(s);

  char **res = malloc(queries_count * sizeof(char *));
  int *map = convertToMap(s, l);

  for (int i = 0; i < queries_count; i++) {
    if (queries[i] > queries_count * 26) {
      res[i] = "No";
    } else {
      if (map[queries[i]] == 1) {
        res[i] = "Yes";
      } else
        res[i] = "No";
    }
  }
  return res;
}

int main() {
  int res_length = 0;
  int q[] = {1, 3, 12, 5, 9, 10};
  int length = sizeof(q) / sizeof(q[0]);
  char **res = weightedUniformStrings("abccddde", length, q, &res_length);

  for (int i = 0; i < res_length; i++) {
    printf("%s\n", res[i]);
  }
}
