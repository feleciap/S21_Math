#ifndef MATH_S21_MATH_H
#define MATH_S21_MATH_H

#include <stdio.h>

#define s21_PI 3.14159265358979324
#define s21_NPI -3.14159265358979324
#define s21_PI_2 1.57079632679
#define s21_NPI_2 -1.57079632679
#define s21_E 2.7182818284590452
#define s21_EPS 1e-17
#define s21_ln10 2.30258509299404590109
#define s21_LN2 0.693147180559945309417232
#define s21_INF 1.0 / 0.0
#define s21_NINF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_N_NAN -0.0 / 0.0
#define s21_DBL_MAX 1.7976931348623157e308
#define s21_DBL_MIN 2.2250738585072014e-308
#define s21_NAN 0.0 / 0.0
#define s21_IS_NAN(x) (x != x)
#define s21_IS_INF(x) (x == s21_INF || x == s21_NINF)
#define s21_tan_PI_2 16331239353195370.;
#define s21_tan_NPI_2 -16331239353195370.;

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_pow_int(double base, int exp);
long double s21_factorial(long long int x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sqrt(double x);

#endif