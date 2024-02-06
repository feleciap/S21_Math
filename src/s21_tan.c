#include "s21_math.h"

long double s21_tan(double x) {
  long double res;
  long double sum_tan = s21_cos(x);
  if (s21_fabs(sum_tan) < s21_EPS) {
    if (x < 0) {
      res = s21_tan_NPI_2;
    } else
      res = s21_tan_PI_2;
  } else
    res = s21_sin(x) / sum_tan;
  return res;
}