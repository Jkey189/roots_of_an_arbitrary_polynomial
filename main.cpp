#pragma optimize( "s", on )


#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


typedef long double ld;

constexpr ld epsilon = 0.00000001;
constexpr ld checkEpsilon = 0.00001;


ld countingValue(const ld root, const std::vector<ld>& pol) {
  ld value = 0.0L;
  ld k = 1;

  for (int i = pol.size() - 1; i >= 0; --i) {
    value += pol[i] * k;
    k *= root;
  }

  return value;
}

ld binarySearch(ld l, ld r, const std::vector<ld>& pol) {
  while (r - l > epsilon) {
    if (const ld mid = l + (r - l) / 2.0L; countingValue(l, pol) * countingValue(mid, pol) > 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return (l + r) / 2.0L;
}

std::vector<ld> givePolynomial(const std::vector<ld>& pol) {
  if (pol.size() <= 1) {
    return {};
  }

  std::vector<ld> polynomial(pol.size() - 1);
  for (size_t i = 0; i < pol.size() - 1; ++i) {
    polynomial[i] = pol[i] * (pol.size() - i - 1);
  }

  return polynomial;
}

std::vector<ld> findRoots(const std::vector<ld>& coefficients, const ld a, const ld b, const int maxPower) {
  // if maxPower (in start) == 2
  if (coefficients.size() == 2) {
    return (a - epsilon <= -coefficients[1] / coefficients[0] && -coefficients[1] / coefficients[0] < b + epsilon)
    ? std::vector{-coefficients[1] / coefficients[0]}
    : std::vector<ld>{};
  }


  std::vector extreme = findRoots(givePolynomial(coefficients), a, b, maxPower - 1);
  std::vector<ld> roots, points;

  // fill points
  points.push_back(a);
  for (auto currRoot : extreme) {
    points.push_back(currRoot);
  }
  points.push_back(b);


  // find roots
  for (int i = 0; i < points.size() - 1; ++i) {
    if (fabs(countingValue(points[i], coefficients)) < epsilon) {
      roots.push_back(points[i]);

      if (i != 0 && points[i - 1] != points[i]/*std::fabs(points[i - 1] - points[i]) > epsilon*/) {
        roots.push_back(points[i]);
      }
    }
  }

  for (int i = 1; i < points.size(); ++i) {
    if (countingValue(points[i - 1], coefficients) * countingValue(points[i], coefficients) < 0) {
      if (const ld currRoot = binarySearch(points[i - 1], points[i], coefficients);
        fabs(points[i - 1] - currRoot) > checkEpsilon && fabs(points[i] - currRoot) > checkEpsilon) {
        roots.push_back(currRoot);
      }
    }
  }

  qsort(roots.data(), roots.size(), sizeof(decltype(roots)::value_type),
    [](const void* x, const void* y) {
      const ld arg1 = *static_cast<const ld*>(x);
      const ld arg2 = *static_cast<const ld*>(y);
      const auto cmp = arg1 <=> arg2;
      return (cmp < nullptr) ? -1 : 1;
    });
  /*std::ranges::sort(roots);*/

  return roots;
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int maxPower;
  std::cin >> maxPower;

  std::vector<ld> coefficients(maxPower + 1);
  for (int i = 0; i < maxPower + 1; ++i) {
    std::cin >> coefficients[i];
  }

  ld a, b;
  std::cin >> a >> b;

  std::vector<ld> roots = findRoots(coefficients, a, b, maxPower);
  for (const auto root : roots) {
    std::cout << std::fixed << std::setprecision(8) << root << ' ';
  }
  std::cout << std::endl;

  return 0;
}
