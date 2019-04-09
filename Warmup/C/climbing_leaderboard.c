#include "conveniences.h"

int* removeDuplicates(int* arr, int arr_length, int* new_length) {
  int res = 0;
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

int countUniques(int* arr, int arr_length) {
  if (arr_length == 1) {
    return 1;
  }
  int counter = 1;
  int prev = arr[0];
  for (int i = 1; i < arr_length; i++) {
    if (arr[i] == prev) {
      continue;
    }
    counter++;
    prev = arr[i];
  }

  return counter;
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
// 6421
int* v2(int scores_count, int* scores, int alice_count, int* alice) {
  int total = countUniques(scores, scores_count);
  int last = scores_count - 1;
  //*result_count = alice_count;

  for (int i = 0; i < alice_count; i++) {
    if (alice[i] >= scores[0]) {
      alice[i] = 1;
      continue;
    }
    if (alice[i] <= scores[last]) {
      alice[i] = total + 1;
      continue;
    }

    int index = 0;
    //int prevIndex = alice[i - 1] > last ? last : alice[i - 1] +1;
    int prevIndex = last;
    int prev = scores[prevIndex];

    for (int j = prevIndex; j >= 1; j--) {
      printf("CHECKING %d and %d\n", alice[i], scores[j]);
      printf("START PREV IS %d\n", prev);
      if (scores[j] == prev) {
        index++;
        continue;
      }
      if (alice[i] == scores[j]) {
        int z = j;
        while (z - 1 != 0 && scores[z] == scores[z - 1]) {
          z--;
          index++;
        }
        alice[i] = total - index + 1;
        break;
      }
      if (alice[i] < scores[j]) {
        alice[i] = total - index + 1;
        break;
      }
      index++;
      prev = scores[j];
      printf("END PREV IS %d\n", prev);
    }
  }

  return alice;
}

int main() {
  int scores[] = {100, 90, 90, 80, 75, 60};
  int scores_length = sizeof(scores) / sizeof(scores[0]);
  int alice[] = {50, 65, 77, 90, 102};
  int alice_length = sizeof(alice) / sizeof(alice[0]);

  simplePrintArray(v2(scores_length, scores, alice_length, alice),
                   alice_length);

  simplePrint(countUniques(scores, scores_length));
}
