#include <stdlib.h>
#include <string.h>

void failure(char* pattern, int* f);
int kmp(char* t, char* p);

int* init_array(int size) {
  int* arr = (int*)malloc(size * sizeof(int));
  int i;
  for(i = 0; i < size; i++) {
    arr[i] = 0;
  }

  return arr;
}

int main(void) {
  char* pattern = "ab";
  char text[50];
  gets(text);
  int match = kmp(text, pattern);
  printf("Match at: %d\n", match);
  system("pause");

  return 0;
}

int kmp(char* t, char* p) {
  int m = strlen(p);
  int n = strlen(t);

  int* f = init_array(m); // Failure function values.
  int i = 0;
  int j = 0;

  while (i < n) {
    if (t[i] == p[j]) {
      if (j == m - 1) {
        return i - j;
      }
      else {
        i += 1;
        j += 1;
      }
    }
    else {
      if (j > 0) {
        j = f[j-1];
      }
      else {
        i += 1;
      }
    }
  }

  return -1;
}

