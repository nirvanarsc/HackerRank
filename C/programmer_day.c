#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkLeapGreg(int year) {
  if (year % 400 == 0) {
    return true;
  }
  if (year % 4 == 0 && year % 100 != 0) {
    return true;
  }
  return false;
}

bool checkLeapJul(int year) { return year % 4 == 0; }

char* dayOfProgrammer(int year) {
  char* date = malloc(20 * sizeof(char));
  char* full_date = malloc(100 * sizeof(char));
  char toStringYear[1024];
  bool (*f)(int);

  if (year == 1918) {
    full_date = "26.09.1918";
    return full_date;
  }

  f = year < 1918 ? checkLeapJul : checkLeapGreg;

  date = f(year) ? "12.09." : "13.09.";
  snprintf(toStringYear, sizeof(toStringYear), "%d", year);
  strcpy(full_date, date);
  strcat(full_date, toStringYear);

  return full_date;
}

int main() {
  printf("%s\n", dayOfProgrammer(2017));
  printf("%s\n", dayOfProgrammer(2000));
  printf("%s\n", dayOfProgrammer(1918));
}
