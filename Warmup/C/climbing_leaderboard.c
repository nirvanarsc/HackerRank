#include "conveniences.h"

int countUniques(int* arr, int arr_length) {
  if (arr_length <= 1) {
    return arr_length;
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
  int total = countUniques(scores, scores_count);
  int last = scores_count - 1;
  int* res = calloc(alice_count, sizeof(int));
  //*result_count = alice_count;

  for (int i = 0; i < alice_count; i++) {
    if (alice[i] <= scores[last]) {
      res[i] = total + 1;
      continue;
    }
    if (alice[i] == alice[i - 1]) {
      res[i] = res[i - 1];
      continue;
    }
    if (alice[i] >= scores[0]) {
      res[i] = 1;
      continue;
    }

    int index = 0;
    // int prevIndex = i > 0 ? res[i - 1] - 1 : last;

    // if (prevIndex > last) {
    //   prevIndex = last;
    // }
    int prevIndex = last;
    int prev = scores[prevIndex];
    printf("PREV INDEX %d\n", prevIndex);
    for (int j = prevIndex; j >= 1; j--) {
      printf("CHECKING %d and %d with previous %d\n", alice[i], scores[j],
             prev);
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
        res[i] = total - index + 1;
        break;
      }
      if (alice[i] < scores[j]) {
        res[i] = total - index + 1;
        break;
      }
      index++;
      prev = scores[j];
    }
  }

  return res;
}

// 10 10 10 7 7 6 4 4 2                 5
// 1 1 1 3 5 7 10 20                6 6 6 5 4 2 1 1

int main() {
  int scores[] = {10, 10, 10, 7, 7, 6, 4, 4, 2};
  int scores_length = sizeof(scores) / sizeof(scores[0]);
  int alice[] = {1, 1, 1, 3, 5, 7, 10, 20};
  int alice_length = sizeof(alice) / sizeof(alice[0]);

  simplePrint(countUniques(scores, scores_length));
  simplePrintArray(
      climbingLeaderboard(scores_length, scores, alice_length, alice),
      alice_length);
}
