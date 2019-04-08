#include "conveniences.h"

int* removeDuplicates(int* arr, int arr_length, int* new_length) {
  int res;
  int curr = 1;
  int i = 0;

  while (i < arr_length) {
    if (curr > arr_length) {
      res = i;
      for (int j = i; j < arr_length; j++) {
        arr[j] = -1;
      }
      break;
    }
    if (arr[i] == arr[curr]) {
      curr++;
      continue;
    }
    arr[i + 1] = arr[curr];
    i++;
  }
  *new_length = res;
  return arr;
}

int* climbingLeaderboard(int scores_count, int* scores, int alice_count,
                         int* alice) {
  int new_length;
  scores = removeDuplicates(scores, scores_count, &new_length);
  //*result_count = alice_count;

  simplePrintArray(scores, new_length);
  for (int i = 0; i < alice_count; i++) {
    if (alice[i] >= scores[0]) {
      alice[i] = 1;
      continue;
    }
    if (alice[i] >= scores[1]) {
      alice[i] = 2;
      continue;
    }
    if (alice[i] <= scores[new_length - 1]) {
      alice[i] = new_length + 1;
      continue;
    }
    for (int j = new_length - 1; j > 1; j--) {
      printf("CHECKING %d and %d\n", scores[j], alice[i]);
      if (scores[j] >= alice[i]) {
        alice[i] = j + 2;
        break;
      }
    }
  }

  return alice;
}

int main() {
  int scores[] = {100, 90, 90, 80, 75, 60};
  int scores_length = sizeof(scores) / sizeof(scores[0]);
  int alice[] = {50, 65, 77, 90, 102};
  int alice_length = sizeof(alice) / sizeof(alice[0]);

  simplePrintArray(
      climbingLeaderboard(scores_length, scores, alice_length, alice),
      alice_length);
}
