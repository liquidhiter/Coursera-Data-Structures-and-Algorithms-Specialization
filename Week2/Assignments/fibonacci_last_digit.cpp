#include <iostream>
#include <vector>

int get_fibonacci_last_digit(int n) {
    std::vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] % 10 + fib[i - 2] % 10) % 10;
    }

    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
