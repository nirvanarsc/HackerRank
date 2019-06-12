#include <math.h>
#include "conveniences.h"

long taumBday(int b, int w, int bc, int wc, int z) {
  int diff = abs(bc - wc);
  int min_cost = bc > wc ? wc : bc;
  int expensive_item = bc > wc ? b : w;

  return diff > z ? (long)(b + w) * min_cost + (long)expensive_item * z
                  : (long)b * bc + (long)w * wc;
}

int main() {
  printf("%ld\n", taumBday(27984, 1402, 619246, 615589, 247954));
  printf("%ld\n", taumBday(95677, 39394, 86983, 311224, 588538));
  printf("%ld\n", taumBday(68406, 12718, 532909, 315341, 201009));
  printf("%ld\n", taumBday(15242, 95521, 712721, 628729, 396706));
  printf("%ld\n", taumBday(21988, 67781, 645748, 353796, 333199));
  printf("%ld\n", taumBday(22952, 80129, 502975, 175136, 340236));
  printf("%ld\n", taumBday(38577, 3120, 541637, 657823, 735060));
  printf("%ld\n", taumBday(5943, 69851, 674453, 392925, 381074));
  printf("%ld\n", taumBday(62990, 61330, 310144, 312251, 93023));
  printf("%ld\n", taumBday(11152, 43844, 788543, 223872, 972572));
}
