// TODO: write a normal programm

int vector_compare(vector *a, vector *b) {
  if (vector_size(a) != vector_size(b)) {
    return 1;
  }
  for (int i = 0; i < vector_size(a); i++) {
    int el1, el2;
    el1 = vector_get_element_at(a, i);
    el2 = vector_get_element_at(b, i);
    if (el1 != el2) {
      return 2;
    }
  }
  return 0;
}

vector *matroid_basis_construction(vector *E, family *Eps) {
  vector *B = vector_create();
  for (int i = 0; i < vector_size(E); i++) {
    int e = vector_get_element_at(E, i);
    vector_push_back(B, e);
    int flag = 0;
    for (int j = 0; j < vector_size(Eps); j++) {
      vector *subset = family_get_element_at(Eps, j);
      if (vector_compare(subset, B) == 0) { // B + e in Eps
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      vector_pop(B);
    }
  }
}

int main() {
  return 0;
}
