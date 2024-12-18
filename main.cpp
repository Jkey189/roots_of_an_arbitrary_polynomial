#include <iostream>
#include <vector>


typedef long double ld;

constexpr ld epsilon = 0.0001;


std::vector<ld> findRoots(std::vector<ld>& coefficients, ld a, ld b, const ld eps) {

}


int main() {
  int COUNT;
  std::cin >> COUNT;

  std::vector<ld> coefficients(COUNT);
  for (int i = 0; i < COUNT; ++i) {
    std::cin >> coefficients[i];
  }

  ld a, b;
  std::cin >> a >> b;

  for (std::vector roots = findRoots(coefficients, a, b, epsilon); const auto root : roots) {
    std::cout << root << ' ';
  }
  std::cout << std::endl;

  return 0;
}
