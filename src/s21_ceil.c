#include "s21_math.h"

long double s21_ceil(double x) {
  long double res;
  if (s21_IS_NAN(x) || s21_IS_INF(x))
    res = x;
  else {
    int int_part = (int)x;
    int_part += (x > 0 && (x - int_part));
    res = int_part;
  }
  if (res == 0 && x < 0) res = -res;
  return res;
}
