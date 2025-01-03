#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  conversion_result status;
  if (dst) {
    status = CONVERSION_OK;
    long int exp = src.bits[3] & 8355840;
    exp >>= 16;
    *dst = (float)(src.bits[0] * pow(10, -exp));
    if (_get_sign_std(src)) {
      *dst = -*dst;
    }
  } else {
    status = CONVERSION_ERROR;
  }
  return status;
}
