int calc_cortege_number(int n, int *x) {
  int d = 0; /* начальное значение индекса */
  for (int i = 0; i < n; i++) {
    d = d << 2;
    if (x[i] == 1) {
      d++; /* добавляем 1, если нужнo */
    }
  }
}
