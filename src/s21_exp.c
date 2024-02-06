#include "s21_math.h"

long double s21_exp(double x) {
  long double res;
  if ((x == x) && (x != -s21_INF)) {
    res = 1;
    long double add = 1, i = 1;
    int check = 0;
    while ((s21_fabs(add) > s21_EPS) && !check) {
      add = add * s21_fabs(x) / i;
      i++;
      res = res + add;
      if (res > s21_DBL_MAX) {
        res = s21_INF;
        check = 1;
      }
    }
    if (x < 0) res = 1 / res;
  } else if (x == -s21_INF)
    res = 0;
  else
    res = s21_NAN;
  return res;
}