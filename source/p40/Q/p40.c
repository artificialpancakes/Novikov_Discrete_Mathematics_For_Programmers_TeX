// TODO

int Q(int i) {
  int q = 0; int j = i;
  while (j % 2 == 0) {
    j = j / 2; q++;
  }
  return q;
}
