#include "s21_math.h"

long double s21_pow_int(double base, int expx) {
  long double res = 1;
  while (expx > 0) {
    res = res * base;
    expx--;
  }
  return res;
}
