#include <stdio.h>

int Q(int i) { // i - номер подмножества.
  int q = 0; int j = i;
  while (j % 2 == 0) {
    j = j / 2; q++;
  }
  return q; // q - номер изменяемого разряда.
}

int main() {
  int i;
  while (fscanf(stdin, "%d", &i) == 1) {
    printf("%s%d%s%d\n", "i: ", i, " Q(i): ", Q(i));
  }
  return 0;
}
