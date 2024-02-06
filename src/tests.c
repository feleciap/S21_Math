#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_factorial(long long int x);
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

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-7), abs(-7));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(3), abs(3));
  ck_assert_int_eq(s21_abs(400), abs(400));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_eq_tol(s21_fabs(-0.7), fabs(-0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.678), fabs(0.678), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-3.78940), fabs(-3.78940), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-s21_ln10), fabs(-s21_ln10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-DBL_MIN), fabs(-DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-DBL_MAX), fabs(-DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(DBL_MIN), fabs(DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(DBL_MAX), fabs(DBL_MAX), 1e-6);
  ck_assert(isinf(s21_fabs(s21_NINF)));
  ck_assert(isinf(s21_fabs(s21_INF)));
  ck_assert(isnan(s21_fabs(s21_NAN)));
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(-0.7), exp(-0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(7.0), exp(7.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(log(654.45)), exp(log(654.45)), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-9.0), exp(-9.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-s21_ln10), exp(-s21_ln10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-s21_DBL_MIN), exp(-s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(s21_DBL_MIN), exp(s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(10.0), exp(10.0), 1e-6);
  ck_assert_ldouble_eq(s21_exp(s21_DBL_MAX), exp(s21_DBL_MAX));
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_nan(s21_exp(-s21_NAN));
  ck_assert_ldouble_eq(s21_exp(s21_INF), exp(s21_INF));
  ck_assert_ldouble_eq(s21_exp(-s21_INF), exp(-s21_INF));
}
END_TEST

START_TEST(test_s21_factorial) {
  ck_assert_ldouble_eq(s21_factorial(9), 362880);
  ck_assert_ldouble_eq(s21_factorial(1), 1);
  ck_assert_ldouble_eq(s21_factorial(0), 1);
  ck_assert_ldouble_eq(s21_factorial(-5), s21_INF);
}
END_TEST

START_TEST(test_s21_sin) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sin(NAN));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sin(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_sin(-14.96), sin(-14.96), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(100000), sin(100000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-10000), sin(-10000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI_2), sin(s21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-s21_PI_2), sin(-s21_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(M_PI), sin(M_PI), 1e-6);
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cos(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_cos(15000), cos(15000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-13.57), cos(-13.57), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(M_PI_2), cos(M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-M_PI_2), cos(-M_PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(M_PI), cos(M_PI), 1e-6);
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
  ck_assert_ldouble_eq_tol(s21_tan(94703), tan(94703), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-15), tan(-15), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(100), tan(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(M_PI), tan(M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(M_PI / 2), tan(M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-M_PI / 2), tan(-M_PI / 2), 1e-6);
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_eq_tol(s21_ceil(-0.3), ceil(-0.3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(-318.6), ceil(-318.6), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(80), ceil(80), 0.000001);
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_ldouble_eq_tol(s21_floor(-18.6), floor(-18.6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0.6), floor(0.6), 1e-6);
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(test_s21_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(653856.387468, 64.1),
                           fmod(653856.387468, 64.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-653856.387468, 64.1),
                           fmod(-653856.387468, 64.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-653856.387468, -64.1),
                           fmod(-653856.387468, -64.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(653856.387468, -64.1),
                           fmod(653856.387468, -64.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(100, 0.11), fmod(100, 0.11), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-100, 0.11), fmod(-100, 0.11), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(100, -0.11), fmod(100, -0.11), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-100, -0.11), fmod(-100, -0.11), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(1, 1), fmod(1, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(s21_DBL_MAX, s21_DBL_MIN),
                           fmod(s21_DBL_MAX, s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(s21_DBL_MAX, -s21_DBL_MIN),
                           fmod(s21_DBL_MAX, -s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-s21_DBL_MAX, -s21_DBL_MIN),
                           fmod(-s21_DBL_MAX, -s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-s21_DBL_MAX, s21_DBL_MIN),
                           fmod(-s21_DBL_MAX, s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0, s21_PI), fmod(0.0, s21_PI), 1e-6);
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(-s21_NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, 1.1));
  ck_assert_ldouble_nan(s21_fmod(-s21_NAN, 1.1));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, 0));
  ck_assert_ldouble_nan(s21_fmod(-s21_INF, 0));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, 1.1));
  ck_assert_ldouble_nan(s21_fmod(-s21_INF, 1.1));
  ck_assert_double_eq(fmod(-1, -s21_INF), s21_fmod(-1, -s21_INF));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(7.0), log(7.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(6541.45), log(6541.45), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(s21_E), log(s21_E), 1e-6);
  ck_assert_ldouble_nan(s21_log(-s21_DBL_MIN));
  ck_assert_ldouble_nan(s21_log(-9.0));
  ck_assert(isinf(s21_log(0.0)));
  ck_assert_ldouble_nan(s21_log(-0.7));
  ck_assert_ldouble_eq_tol(s21_log(s21_DBL_MAX), log(s21_DBL_MAX), 1e-6);
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_nan(s21_log(-s21_NAN));
  ck_assert_ldouble_eq(s21_log(s21_INF), log(s21_INF));
  ck_assert_ldouble_nan(s21_log(-s21_INF));
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(65.4, 4.1), pow(65.4, 4.1), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-654.45, 4.1));
  ck_assert_ldouble_nan(s21_pow(-654.45, -4.1));
  ck_assert_ldouble_eq_tol(s21_pow(654.45, -4.1), pow(654.45, -4.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(100, 0.1), pow(100, 0.1), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-100, 0.1));
  ck_assert_ldouble_eq_tol(s21_pow(100, -0.1), pow(100, -0.1), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-100, -0.1));
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_DBL_MAX, s21_DBL_MIN),
                           pow(s21_DBL_MAX, s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_DBL_MAX, -s21_DBL_MIN),
                           pow(s21_DBL_MAX, -s21_DBL_MIN), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-s21_DBL_MAX, -s21_DBL_MIN));
  ck_assert_ldouble_nan(s21_pow(-s21_DBL_MAX, s21_DBL_MIN));
  ck_assert_ldouble_eq(s21_pow(1, 0), pow(1, 0));
  ck_assert_ldouble_eq(s21_pow(s21_NAN, 0), pow(s21_NAN, 0));
  ck_assert_ldouble_eq(s21_pow(-s21_NAN, 0), pow(-s21_NAN, 0));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, 1.1));
  ck_assert_ldouble_nan(s21_pow(-s21_NAN, 1.1));
  ck_assert_ldouble_eq(s21_pow(s21_INF, 0), pow(s21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(-s21_INF, 0), pow(-s21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(s21_INF, 1.1), pow(s21_INF, 1.1));
  ck_assert_ldouble_eq(s21_pow(-s21_INF, 1.1), pow(-s21_INF, 1.1));
  ck_assert_ldouble_eq_tol(s21_pow(0, 4.1), pow(0, 4.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 4), pow(0, 4), 1e-6);
  ck_assert_ldouble_nan(s21_pow(0, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(0, -s21_NAN));
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, s21_INF), pow(0, s21_INF), 1e-6);
  ck_assert_ldouble_eq(s21_pow(0, -s21_INF), pow(0, -s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(-1, s21_INF), pow(-1, s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -s21_INF), pow(-1, -s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_INF), pow(1, s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -s21_INF), pow(1, -s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_NAN), pow(1, s21_NAN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -s21_NAN), pow(1, -s21_NAN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 2), pow(1, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -2), pow(1, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 2.2), pow(1, 2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -2.2), pow(1, -2.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, 0), pow(2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 0), pow(-2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2.2, 0), pow(2.2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2.2, 0), pow(-2.2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.1, s21_INF), pow(0.1, s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0.1, s21_INF), pow(-0.1, s21_INF), 1e-6);
  ck_assert_ldouble_eq(s21_pow(0.1, -s21_INF), pow(0.1, -s21_INF));
  ck_assert_ldouble_eq(s21_pow(-0.1, -s21_INF), pow(-0.1, -s21_INF));
  ck_assert_ldouble_eq(s21_pow(1.1, s21_INF), pow(1.1, s21_INF));
  ck_assert_ldouble_eq(s21_pow(-1.1, s21_INF), pow(-1.1, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(1.1, -s21_INF), pow(1.1, -s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1.1, -s21_INF), pow(-1.1, -s21_INF), 1e-6);
  ck_assert_ldouble_eq(s21_pow(2, s21_INF), pow(2, s21_INF));
  ck_assert_ldouble_eq(s21_pow(-2, s21_INF), pow(-2, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(2, -s21_INF), pow(2, -s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -s21_INF), pow(-2, -s21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_INF, -1.1), pow(s21_INF, -1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INF, -1.1), pow(-s21_INF, -1.1), 1e-6);
  ck_assert_ldouble_eq(s21_pow(s21_INF, 0.1), pow(s21_INF, 0.1));
  ck_assert_ldouble_eq(s21_pow(-s21_INF, 0.1), pow(-s21_INF, 0.1));
  ck_assert_ldouble_eq_tol(s21_pow(s21_INF, -0.1), pow(s21_INF, -0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INF, -0.1), pow(-s21_INF, -0.1), 1e-6);
  ck_assert_ldouble_eq(s21_pow(s21_INF, 2), pow(s21_INF, 2));
  ck_assert_ldouble_eq(s21_pow(-s21_INF, 2), pow(-s21_INF, 2));
  ck_assert_ldouble_eq_tol(s21_pow(s21_INF, -2), pow(s21_INF, -2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INF, -2), pow(-s21_INF, -2), 1e-6);
  ck_assert_ldouble_eq(s21_pow(s21_INF, s21_INF), pow(s21_INF, s21_INF));
  ck_assert_ldouble_eq(s21_pow(-s21_INF, s21_INF), pow(-s21_INF, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(s21_INF, -s21_INF), pow(s21_INF, -s21_INF),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INF, -s21_INF), pow(-s21_INF, -s21_INF),
                           1e-6);
  ck_assert_ldouble_nan(s21_pow(s21_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(-s21_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_INF, -s21_NAN));
  ck_assert_ldouble_nan(s21_pow(-s21_INF, -s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(-s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, -s21_NAN));
  ck_assert_ldouble_nan(s21_pow(-s21_NAN, -s21_NAN));
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(-14.96));
  ck_assert_ldouble_nan(s21_asin(-s21_PI_2));
  ck_assert_ldouble_nan(s21_asin(s21_PI_2));
  ck_assert_ldouble_nan(s21_asin(M_PI));
  ck_assert_ldouble_nan(asin(round(-14.96)));
  ck_assert_ldouble_nan(asin(round(-s21_PI_2)));
  ck_assert_ldouble_nan(asin(round(s21_PI_2)));
  ck_assert_ldouble_nan(asin(round(M_PI)));
  ck_assert_ldouble_eq_tol(s21_asin(0.76980453), asin(0.76980453), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(-14.96));
  ck_assert_ldouble_nan(s21_acos(-s21_PI_2));
  ck_assert_ldouble_nan(s21_acos(s21_PI_2));
  ck_assert_ldouble_nan(s21_acos(M_PI));
  ck_assert_ldouble_nan(acos(round(-14.96)));
  ck_assert_ldouble_nan(acos(round(-s21_PI_2)));
  ck_assert_ldouble_nan(acos(round(s21_PI_2)));
  ck_assert_ldouble_nan(acos(round(M_PI)));
  ck_assert_ldouble_eq_tol(s21_acos(0.76980453), acos(0.76980453), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(-13.7687), atan(-13.7687), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(325.976), atan(325.976), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(s21_PI), atan(s21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(6), atan(6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(98767), atan(98767), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.98765), atan(0.98765), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-45.0), atan(-45.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(s21_NINF), atan(s21_NINF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0));
  ck_assert_ldouble_eq_tol(s21_sqrt(64.0), sqrt(64.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(43), sqrt(43), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(7789.87), sqrt(7789.87), 1e-6);
  ck_assert(isnan(s21_sqrt(-1)));
  ck_assert(isnan(sqrt(round(-1.0))));
  ck_assert(isnan(s21_sqrt(s21_NINF)));
  ck_assert(isnan(sqrt(s21_NINF)));
  ck_assert(isinf(s21_sqrt(INFINITY)));
  ck_assert(isinf(sqrt(INFINITY)));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_math");
  tc_core = tcase_create("Core");

  tcase_set_timeout(tc_core, 10);
  tcase_add_test(tc_core, test_s21_abs);
  tcase_add_test(tc_core, test_s21_fabs);
  tcase_add_test(tc_core, test_s21_exp);
  tcase_add_test(tc_core, test_s21_factorial);
  tcase_add_test(tc_core, test_s21_sin);
  tcase_add_test(tc_core, test_s21_cos);
  tcase_add_test(tc_core, test_s21_tan);
  tcase_add_test(tc_core, test_s21_ceil);
  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_fmod);
  tcase_add_test(tc_core, test_s21_log);
  tcase_add_test(tc_core, test_s21_pow);
  tcase_add_test(tc_core, test_s21_atan);
  tcase_add_test(tc_core, test_s21_asin);
  tcase_add_test(tc_core, test_s21_acos);
  tcase_add_test(tc_core, test_s21_sqrt);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}