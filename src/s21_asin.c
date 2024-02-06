#include "s21_math.h"

long double s21_asin(double x) {
  long double sum_asin;
  if (x > 1 || x < -1) {
    sum_asin = s21_NAN;
  } else if (x == 1 || x == -1) {
    sum_asin = s21_PI / (2 * x);
  } else {
    sum_asin = s21_PI / 2 - s21_acos(x);
  }
  return sum_asin;
}
