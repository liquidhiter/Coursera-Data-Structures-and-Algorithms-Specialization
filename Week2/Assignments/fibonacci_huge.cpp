#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// The following algorithm can give the correct answer but it is still too slow
// The time complexity is O(n)
long long get_fibonacci_huge_naive_two(long long n, long long m) {
    assert(n >= 1 && n <= 10E14);
    assert(m >= 2 && m <= 10E3);

    if (n <= 1) {
        return n;
    }

    std::vector<long long> fib(3);
    fib[0] = 0;
    fib[1] = 1;
    for (long long i = 2; i <= n; ++i) {
        fib[2] = (fib[1] % m + fib[0] % m) % m;
        fib[0] = fib[1];
        fib[1] = fib[2];
    }

    return fib[2];
}

long long get_fibonacci_huge(long long n, long long m) {
    assert(n >= 1 && n <= 10E14);
    assert(m >= 2 && m <= 10E3);

    // Find the pattern for m
    std::vector<long long> pattern(10000);
    pattern[0] = 0;
    pattern[1] = 1;
    for (int i = 2; i < 10000; ++i) {
        pattern[i] = (pattern[i - 1] % m + pattern[i - 2] % m) % m;
    }

    // Find the numbers of the pattern O(n^2)
    int first = pattern[0], cycleNum = 0;
    for (int i = 1; i < 10000; ++i) {
        if (pattern[i] == first) {
            bool findFlag = true;
            for (int j = 1; j < i; ++j) {
                if (pattern[j] != pattern[i + j]) {
                    findFlag = false;
                    break;
                }
            }
            if (findFlag) {
                cycleNum = i;
                break;
            }
        }
    }

    return pattern[n % cycleNum];

}

void test_solution() {
    assert(get_fibonacci_huge_naive(1, 1000) == get_fibonacci_huge(1, 1000));
    assert(get_fibonacci_huge_naive(10, 2) == get_fibonacci_huge(10, 2));
    // Big number input
    assert(get_fibonacci_huge(115, 1000) == 885);
    assert(get_fibonacci_huge(2816213588, 239) == 151);
    // Stress Test
    // Randomizing...
    srand(time(nullptr));
    for (int i = 1; i <= 20; ++i) {
        int j = rand() % 999 + 2;
        assert(get_fibonacci_huge_naive(i, j) == get_fibonacci_huge(i, j));
    }
}


int main() {
    // test_solution();
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge(n, m) << std::endl;
}
