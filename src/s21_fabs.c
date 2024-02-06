#include "s21_math.h"

long double s21_fabs(double x) {
  if (x != s21_INF && x != s21_NINF && x != s21_NAN) {
    if (x < 0) x = x * -1;
  } else
    x = s21_INF;
  return x;
}
