int Q(int i) {
  int q = 1; int j = 1;
  while (j % 2 == 0) {
    j = j / 2; q++;
  }
  return q;
}
