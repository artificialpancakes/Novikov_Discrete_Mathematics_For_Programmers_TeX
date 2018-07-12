#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*#include "vector.h"
#define VECTOR_TYPE double;*/

typedef struct {
  int flag;
  int p;
  double *T;
  int *H;
} result;

result dijkstra_algorithm(int p, double *C, int s, int t) {
  result res;
  double *T = malloc(sizeof(double) * p);
  int *H = malloc(sizeof(int) * p);
  res.T = T; res.H = H;
  double X[p];
  for (int i = 0; i < p; i++) {
    T[i] = INFINITY; /* кратчайший путь неизвестен */
    X[i] = 0; /* все вершины не отмечены */
  }
  H[s] = -1; /* ничего не предшествует */
  T[s] = 0; /* кратчайший путь имеет длину 0, */
  X[s] = 1; /* и он известен */
  int v = s; /* текущая вершина */
  M: /* обновление пометок */
  for (int u = 0; u < p; u++) {
    double length = C[v + u * p];
    if (length == INFINITY) {
      continue;
    }
    if ((X[u] == 0) && (T[u] > (T[v] + length))) {
      /* найден более короткий путь из s в u через v */
      T[u] = T[v] + length;
      H[u] = v; /* запоминаем его */
    }
  }
  double m = INFINITY; v = -1;
  /* поиск конца кратчайшего пути */
  for (int u = 0; u < p; u++) {
    if (X[u] == 0 && T[u] < m) {
      /* вершина v заканчивает кратчайший путь из s */
      v = u; m = T[u];
    }
  }
  if (v == t) {
    /* нет пути из s в t */
    res.flag = 0;
    return res;
  }
  if (v == -1) {
    /* найден кратчайший путь из s в t */
    res.flag = -1;
    return res;
  }
  /* найден кратчайший путь из s в v */
  X[v] = 1; 
  goto M;
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

  printf("%s\n", "enter matrix: ");
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

  int from, to;
  printf("%s\n", "from:");
  scanf("%d", &from);
  printf("%s\n", "to:");
  scanf("%d", &to);

  printf("%s\n", "-----");

  result res = dijkstra_algorithm(p, C, from, to);
  if (res.flag == -1) {
    printf("%s\n\n", "!found!");
  }
  else {
    printf("%s\n", "found!");
  }

  printf("%s", "H: ");
  for (int i = 0; i < p; i++) {
    printf("%d ", res.H[i]);
  }
  printf("\n\n%s", "T: ");
  for (int i = 0; i < p; i++) {
    printf("%.0lf ", res.T[i]);
  }
  printf("%s\n", "");

  return 0;
}
