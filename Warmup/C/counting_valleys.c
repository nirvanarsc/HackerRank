#include "conveniences.h"

int countingValleys(int n, char* s) {
  int currLevel = 0;
  int valley_number = 0;

  for (int i = 0; i < n; i++) {
    if (currLevel == -1 && s[i] == 'U') {
      valley_number++;
    }
    s[i] == 'U' ? currLevel++ : currLevel--;
  }
  return valley_number;
}

int main() {
  char hike1[] = {'U', 'D', 'D', 'D', 'U', 'D', 'U', 'U'};
  int n1 = sizeof(hike1) / sizeof(hike1[0]);
  char hike2[] = {'D', 'D', 'U', 'U', 'D', 'D', 'U', 'D', 'U', 'U', 'U', 'D'};
  int n2 = sizeof(hike2) / sizeof(hike2[0]);
  simplePrint(countingValleys(n1, hike1));
  simplePrint(countingValleys(n2, hike2));
}
