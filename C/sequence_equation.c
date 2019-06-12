#include "conveniences.h"

int check(int p_count, int* p, int k) {
  int res = 0;
  for (int i = 0; i < p_count; i++) {
    if (p[i] == k) {
      res = i + 1;
      break;
    }
  }
  return res;
}

int* permutationEquation(int p_count, int* p, int* result_count) {
  int* res = malloc(p_count * sizeof(int));
  *result_count = p_count;
  for (int x = 1; x <= p_count; x++) {
    res[x - 1] = check(p_count, p, check(p_count, p, x));
  }
  return res;
}

int main() {
  int p[] = {5, 2, 1, 3, 4};
  int p_length = sizeof(p) / sizeof(p[0]);
  int length = 0;
  int* res = permutationEquation(p_length, p, &length);
  simplePrintArray(res, length);
}
