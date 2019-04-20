#include "conveniences.h"

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
  return (y1 - y2) > 0
             ? 10000
             : (y1 - y2) < 0
                   ? 0
                   : (m1 - m2) > 0
                         ? (m1 - m2) * 500
                         : (m1 - m2) < 0 ? 0
                                         : (d1 - d2) > 0 ? (d1 - d2) * 15 : 0;
}

int main() {
  simplePrint(libraryFine(9, 6, 2015, 6, 6, 2015));
  simplePrint(libraryFine(1, 1, 2018, 31, 12, 2017));
}
