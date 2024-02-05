#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res_sqrt;
  if (x == s21_NINF) {
    res_sqrt = s21_NAN;
  } else {
    res_sqrt = s21_pow(x, 0.5);
  }
  return res_sqrt;
}