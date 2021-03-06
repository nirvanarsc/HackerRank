#include <stdio.h>
#include <stdlib.h>

int *gradingStudents(int grades_count, int *grades, int *result_count) {
  int *res = malloc(grades_count * sizeof(int));
  *result_count = grades_count;
  for (int i = 0; i < grades_count; i++) {
    if (grades[i] >= 38 && grades[i] < 100) {
      if (grades[i] % 5 > 2) {
        res[i] = grades[i] + (5 - grades[i] % 5);
      } else
        res[i] = grades[i];
    } else
      res[i] = grades[i];
  }

  return res;
}

int main() {
  int grades_count = 4;
  int grades[] = {73, 67, 38, 33};
  int *result_count = malloc(grades_count * sizeof(int));
  int *res = gradingStudents(grades_count, grades, result_count);

  for (int i = 0; i < grades_count; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
