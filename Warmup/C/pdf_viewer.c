#include <string.h>
#include "conveniences.h"

int designerPdfViewer(int h_count, int* h, char* word) {
  int max_height = 0;
  int word_length = strlen(word);

  for (int i = 0; i < word_length; i++) {
    if (h[word[i] - 97] > max_height) {
      max_height = h[word[i] - 97];
    }
  }

  return word_length * max_height;
}

int main() {
  int h[] = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5,
             5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
  int h_length = sizeof(h) / sizeof(h[0]);
  char* word = "zaba";
  simplePrint(designerPdfViewer(h_length, h, word));
}
