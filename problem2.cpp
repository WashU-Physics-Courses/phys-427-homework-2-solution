#include "problem1.h"
#include <iostream>

int main() {
  double M1 = 1.989e30; // in kg
  double M2 = 5.972e24; // in kg
  double mu = M2 / (M1 + M2);
  auto L1 = [mu] (double x) {
    return (1.0 - mu) / std::pow(1.0 - x, 2) - mu / std::pow(x, 2) - (1.0 - mu - x);
  };

  auto L2 = [mu] (double x) {
    return (1.0 - mu) / std::pow(1.0 + x, 2) + mu / std::pow(x, 2) - (1.0 - mu + x);
  };

  auto L3 = [mu] (double x) {
    return (1.0 - mu) / std::pow(1.0 - x, 2) + mu / std::pow(2.0 - x, 2) - (mu + 1 - x);
  };

  auto x1 = bisection(L1, 1e-5, 0.1, 1e-12);
  auto x2 = bisection(L2, 1e-5, 0.1, 1e-12);
  auto x3 = bisection(L3, -0.1, 0.1, 1e-12);

  std::cout << "r1: " << std::get<1>(x1) << "R" << std::endl;
  std::cout << "r2: " << std::get<1>(x2) << "R" << std::endl;
  std::cout << "r3: " << std::get<1>(x3) << "R" << std::endl;

  return 0;
}
