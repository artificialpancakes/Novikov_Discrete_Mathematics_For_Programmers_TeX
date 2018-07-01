vector* gray_binary_code(int n) {
  vector* out = malloc(sizeof(vector)); // return
  int *B = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    B[i] = 0;
  }
  vector_pushback(out, B);

  for (int i = 0; i < pow(2, n); i++) {
    int p = Q(i);
    B[p] = 1 - B[p];
    vector_pushback(out, B); 
  }

  return out;
}
