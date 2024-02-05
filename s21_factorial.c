#include "s21_math.h"

long double s21_factorial(long long int x) {
  long double factor;
  if (x == 1 || x == 0)
    factor = 1;
  else if (x < 0)
    factor = s21_INF;
  else
    factor = x * s21_factorial(x - 1);
  return factor;
}
