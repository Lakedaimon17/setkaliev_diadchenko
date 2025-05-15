#include "root.h"

int root(double a, double b, double c, double *roots, int *num_roots,
         double eps) {
  double D, x1, x2;
  if (fabs(a) <= eps) {
    return -1;
  }
  D = b * b - 4 * a * c;
  if (D < 0) {
    return -2;
  } else if (fabs(D) <= eps) {
    x1 = -b / (2 * a);
    if (x1 == 0.0) {
      x1 = fabs(x1);
    }
    roots[0] = x1;
    *num_roots = 1;
    return 0;
  } else {
    if (b < 0) {
      x1 = (-b + sqrt(D)) / (2 * a);
    } else {
      x1 = (-b - sqrt(D)) / (2 * a);
    }
    x2 = c / (a * x1);
    if (x1 > x2) {
      double temp = x1;
      x1 = x2;
      x2 = temp;
    }
    roots[0] = x1;
    roots[1] = x2;
    *num_roots = 2;
    return 0;
  }
}
