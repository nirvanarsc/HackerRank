#include <stdbool.h>
#include "conveniences.h"

int *convertToMap(char *s, int l) {
  int *map = calloc(1000000, sizeof(int));

  char prev;
  int repeated = 2;
  for (int i = 0; i < l; i++) {
    if (s[i] == prev) {
      int x = (s[i] - '`') * repeated++;
      if (x > 1000000) {
        continue;
      }
      if (map[x] == 0) {
        map[x] = 1;
      }
      continue;
    }
    if (map[s[i] - '`'] == 0) {
      map[s[i] - '`'] = 1;
    }
    prev = s[i];
    repeated = 2;
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
      if (map[queries[i]] == 0) {
        res[i] = "No";
      } else
        res[i] = "Yes";
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
