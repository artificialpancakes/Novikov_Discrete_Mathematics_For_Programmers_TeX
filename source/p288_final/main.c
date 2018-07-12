#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double* dijkstra_algorithm(int p, double *C, int s) {
  double *T = malloc(sizeof(double) * p);
  int X[p];
  for (int i = 0; i < p; i++) {
    T[i] = C[s + i * p]; /* начальное приближение определяется матрицей */
    X[i] = 0; /* все вершины не отмечены */
  }
  for (int i = 0; i < p; i++) {
    int v;
    double m = INFINITY; /* поиск конца нового кратчайшего пути */
    for (int u = 0; u < p; u++) {
      if ((X[u] == 0) && (T[u] < m)) {
        /* вершина v заканчивает новый кратчайший путь из s */
        v = u; m = T[u];
      }
    }
    for (int u = 0; u < p; u++) {
      double length = C[v + u * p];
      if (length == INFINITY) {
        continue;
      }
      /* пересчёт оценки длины пути из s в u через v */
      T[u] = fmin(T[u], T[v] + length);
    }
    X[v] = 1; /* найден кратчайший путь из s в v */
  }
  return T;
}

int main() {
  int p;
  double *C;

  printf("%s\n", "enter number of vertices: ");
  if (scanf("%d", &p) != 1) {
    printf("%s\n", "error!");
    return 1;
  }
  C = malloc(p * p * sizeof(double));
  memset(C, -1.0, sizeof(double) * p * p);

  printf("%s\n", "enter distances for each vertex: ");
  int col = 0, row = 0;
  int d;
  while (scanf("%lf", C + (row + col * p)) == 1) {
    if (C[row + col * p] == -1) {
      C[row + col * p] = INFINITY;
    }
    col++;
    if (col == p) {
      col = 0;
      row++;
      if (row == p) {
        break;
      }
    }
  }
  if (row != p) {
    printf("%s\n", "error");
    return 2;
  }

  printf("%s\n", "-----");

  for (row = 0; row < p; row++) {
    for (col = 0; col < p; col++) {
      printf("%4.0lf ", C[col + row * p]);
    }
    printf("%s\n", "");
  }

  printf("%s\n", "-----");

  int from;
  printf("%s\n", "from:");
  scanf("%d", &from);

  printf("%s\n", "-----");

  double *res = dijkstra_algorithm(p, C, from);
  for (int i = 0; i < p; i++) {
    printf("%.0lf ", res[i]);
  }
  printf("%s\n", "");

  return 0;
}
