/* ************************************************************************
> File Name:     find_largest_concatenate.cpp
> Author:        MinXu
> Mail:          minxu@kth.se
> Created Time:  Fri 04 Nov 2022 09:21:41 PM CET
> Description:   
 ************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <vector>

typedef long long ll;

// Time Complexity: O(n)
ll find_largest_concatenate(std::vector<int> numbers) {
    assert(numbers.size() > 0);
    sort(numbers.begin(), numbers.end());
    ll largest_number = 0;
    ll multiplier = 1;
    size_t size_of_numbers = numbers.size();
    for (size_t i = 0; i < size_of_numbers; ++i) {
        std::cout << "current i = " << i << std::endl;
        largest_number += numbers.at(i) * multiplier;
        multiplier *= 10;
    }

    return largest_number;
}

void test_solution() {
    std::vector<int> numbers_vector1 {0};
    assert(find_largest_concatenate(numbers_vector1) == 0);

}

int main() {

    // test_solution();
    
    int n, tmp;
    std::cout << "Please Enter Numbers To be Input: ";
    std::cin >> n;
    std::vector<int> numbers;
    std::cout << "Please Enter " << n << " Numbers: \n";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> tmp;
        numbers.push_back(tmp);
    }

    std::cout << "The largest concatenated number is: " << find_largest_concatenate(numbers) << std::endl;

    return 0;
}
