#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int makingAnagrams(char* s1, char* s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);

  int* map1 = calloc(26, sizeof(int));
  int* map2 = calloc(26, sizeof(int));

  for (int i = 0; i < l1; i++) {
    map1[s1[i] - 'a']++;
  }
  for (int i = 0; i < l2; i++) {
    map2[s2[i] - 'a']++;
  }

  int res = 0;

  for (int i = 0; i < 26; i++) {
    res += abs(map1[i] - map2[i]);
  }

  return res;
}

int main() {
  printf("%d\n", makingAnagrams("cde", "abc"));
  printf("%d\n", makingAnagrams("absdjkvuahdakejfnfauhdsaavasdlkj",
                                "djfladfhiawasdkjvalskufhafablsdkashlahdfa"));
}
