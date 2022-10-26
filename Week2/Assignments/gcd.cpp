#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return gcd(b, a %= b);
}

void test_solution() {
    assert(gcd_naive(10, 20) == 10);
    assert(gcd_naive(45, 99) == 9);
    assert(gcd_naive(1, 1) == gcd(1, 1));
    assert(gcd_naive(2, 4) == gcd(2, 4));
    assert(gcd_naive(17, 15) == gcd(15, 17));
    for (int i = 10; i <= 30; ++i) {
      for (int j = 15; j <= 35; ++j) {
        assert(gcd_naive(i, j) == gcd(i, j));
      }
    }
}

int main() {
  // test_solution();
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
