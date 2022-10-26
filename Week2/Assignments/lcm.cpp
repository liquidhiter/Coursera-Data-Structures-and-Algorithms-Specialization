#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}


// Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return gcd(b, a %= b);
}

long long lcm(int a, int b) {
    // Corner cases
    if (a == 0 || b == 0) {
        return 0;
    }

    if (a % b == 0) {
        return a;
    }

    if (b % a == 0) {
        return b;
    }

    // Calculate the gcd of a and b
    int gcdOfAB = gcd(a, b);
    // mulOfA and mulOfB must be Coprime
    int mulOfA = a / gcdOfAB, mulOfB = b / gcdOfAB;

    return (long long) gcdOfAB * mulOfA * mulOfB;
}


// int genRandInput(int maxVal) {
//     srand(time(nullptr));
//     return rand() % maxVal + 1;
// }

void test_solution() {
    // Randomizing...
    srand(time(nullptr));

    assert(lcm_naive(10, 15) == 30);
    assert(lcm_naive(144, 3) == 144);
    assert(lcm_naive(1, 1) == lcm(1, 1));
    assert(lcm_naive(2, 8) == lcm(2, 8));
    for (int i = 0; i <= 20; ++i) {
        int a = rand() % 1000 + 1;
        int b = rand() % 1000 + 1;
        assert(lcm_naive(a, b) == lcm(a, b));
    }
}


int main() {
    // test_solution();
    int a, b;
    std::cin >> a >> b;
    // std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
