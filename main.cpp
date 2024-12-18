#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <semaphore>


typedef long double ld;

constexpr ld epsilon = 0.00000001;


ld countingValue(ld root, const std::vector<ld>& pol);


ld binarySearch(ld l, ld r, const std::vector<ld>& pol) {
  while (r - l > epsilon) {
    if (const ld mid = l + (r - l) / 2.0; countingValue(l, pol) * countingValue(mid, pol) > 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return (l + r) / 2.0;
}

ld countingValue(const ld root, const std::vector<ld>& pol) {
  ld value = 0.0;
  ld k = 1;

  for (int i = static_cast<int>(pol.size()) - 1; i > -1; --i) {
    value += pol[i] * k;
    k *= root;
  }

  return value;
}

std::vector<ld> givePolynomial(const std::vector<ld>& pol) {
  std::vector<ld> polynomial;
  const ld length = pol.size();

  for (size_t i = 0; i < length - 1; ++i) {
    polynomial.push_back(pol[i] * (length - i - 1));
  }

  return polynomial;
}

std::vector<ld> findRoots(const std::vector<ld>& coefficients, ld a, ld b, const size_t maxPower) {
  const ld tmpA = a, tmpB = b;
  a = (a > b) ? b : a;
  b = (a == tmpB && tmpA != tmpB) ? tmpA : tmpB;

  // if maxPower (in start) == 2
  if (coefficients.size() == 2) {
    if (const ld root = -coefficients[1] / coefficients[0]; a <= root && root < b) {
      std::vector<ld> roots;
      const ld currRoot = (coefficients[1] == 0) ? 0.0 : root;
      roots.push_back(currRoot);
      return roots;
    }
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
  for (size_t i = 0; i < points.size() - 1; ++i) {
    if (std::fabs(countingValue(points[i], coefficients)) < epsilon) {
      roots.push_back(points[i]);

      if (i != 0 && points[i - 1] != points[i]) {
        roots.push_back(points[i]);
      }
    }
  }

  for (size_t i = 1; i < points.size(); ++i) {
    if (countingValue(points[i - 1], coefficients) * countingValue(points[i], coefficients) < 0) {
      if (const ld currRoot = binarySearch(points[i - 1], points[i], coefficients);
        fabs(points[i - 1] - currRoot) > sqrt(epsilon) && fabs(points[i] - currRoot) > sqrt(epsilon)) {
        roots.push_back(currRoot);
      }
    }
  }

  std::ranges::sort(roots);

  return roots;
}


int main() {
  int maxPower;
  std::cin >> maxPower;

  std::vector<ld> coefficients(maxPower + 1);
  for (int i = 0; i < maxPower + 1; ++i) {
    std::cin >> coefficients[i];
  }

  ld a, b;
  std::cin >> a >> b;

  for (std::vector roots = findRoots(coefficients, a, b, maxPower); const auto root : roots) {
    std::cout << std::fixed << std::setprecision(8) << root << ' ';
  }
  std::cout << std::endl;

  return 0;
}
