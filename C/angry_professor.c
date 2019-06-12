#include <stdio.h>

char* angryProfessor(int k, int a_count, int* a) {
  char* yes = "YES";
  char* no = "NO";
  int students = 0;
  for (int i = 0; i < a_count; i++) {
    if (a[i] <= 0) {
      students++;
    }
  }
  return students >= k ? no : yes;
}

int main() {
  int len = 10;
  int arr1[] = {-93, -86, 49, -62, -90, -63, 40, 72, 11, 67};
  int arr2[] = {-50, 0, 64, 14, -56, -91, -65, -36, 51, -28};
  int arr3[] = {-58, -29, -35, -18, 43, -28, -76, 43, -13, 6};
  int arr4[] = {88, -17, -96, 43, 83, 99, 25, 90, -39, 86};

  printf("%s\n", angryProfessor(4, len, arr1));
  printf("%s\n", angryProfessor(9, len, arr2));
  printf("%s\n", angryProfessor(6, len, arr3));
  printf("%s\n", angryProfessor(1, len, arr4));
}
