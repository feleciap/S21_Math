#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0;
  if (x != s21_INF || x != s21_NINF || !s21_IS_NAN(x))
    res = s21_sin(s21_PI / 2 - x);
  return res;
}