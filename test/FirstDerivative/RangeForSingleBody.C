// RUN: %cladclang %s -I%S/../../include -oRangeForSingleBody.out
// RUN: ./RangeForSingleBody.out | %filecheck_exec %s

#include "clad/Differentiator/Differentiator.h"

#include <cstdio>

double rangeForSingleBody(double x) {
  double values[] = {1, 2, 3};
  double result = 0;
  for (double value : values)
    result += x;
  return result;
}

int main() {
  auto d = clad::differentiate(rangeForSingleBody, "x");
  std::printf("%.2f\n", d.execute(2));
  // CHECK-EXEC: 3.00
}
