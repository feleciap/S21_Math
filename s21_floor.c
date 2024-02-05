#include "s21_math.h"

long double s21_floor(double x) {
  long double res;
  if (s21_IS_INF(x) || s21_IS_NAN(x))
    res = x;
  else {
    int int_part = (int)x;
    int_part -= (x < 0 && (x - int_part));
    res = (long double)int_part;
  }
  return res;
}
