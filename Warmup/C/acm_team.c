#include <string.h>
#include "conveniences.h"

int* acmTeam(int topic_count, char** topic, int* result_count) {
  *result_count = 2;
  int* res = malloc(*result_count * sizeof(int));
  int topic_size = strlen(topic[0]);
  int max = INT_MIN;
  int count = 0;

  for (int i = 1; i <= topic_count; i++) {
    for (int j = i + 1; j <= topic_count; j++) {
      int total = 0;
      for (int k = 0; k < topic_size; k++) {
        if (topic[i - 1][k] == '1' || topic[j - 1][k] == '1') {
          total++;
        }
      }
      if (total > max) {
        max = total;
        count = 0;
      }
      if (total == max) {
        count++;
      }
    }
  }

  res[0] = max;
  res[1] = count;
  return res;
}

int main() {
  int topic_count = 4;
  int result_count = 0;
  char* topic[] = {"10101", "11100", "11010", "00101"};
  int* res = acmTeam(topic_count, topic, &result_count);
  simplePrintArray(res, result_count);

  int topic_count2 = 6;
  int result_count2 = 0;
  char* topic2[] = {"11101", "10101", "11001", "10111", "10000", "01110"};
  int* res2 = acmTeam(topic_count2, topic2, &result_count2);
  simplePrintArray(res2, result_count2);
}
