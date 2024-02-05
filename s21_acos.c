#include "s21_math.h"

long double s21_acos(double x) {
  long double sum_acos = s21_NAN;
  if (x < 1 && x >= 0) sum_acos = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0 && x > -1) sum_acos = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (x == 1) sum_acos = 0;
  if (x == -1) sum_acos = s21_PI;
  return sum_acos;
}
