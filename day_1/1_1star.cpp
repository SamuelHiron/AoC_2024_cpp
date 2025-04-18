#include <array>
#include <iostream>
#include <algorithm> // pour std::abs et ranges::sort
#include <cmath>
#include <fmt/core.h>
#include <numeric> // Pour std::transform_reduce

const int nb_lines = 1000;
int main()
{
    std::array<int, nb_lines> a;
    std::array<int, nb_lines> b;
    for(size_t i = 0; i<nb_lines; i++)
    {
        if(!(std::cin >> a[i] >>b[i]))
        {
            fmt::println(stderr, "Error reading input at line {}", i + 1);
            return 1;
        }
    }

    std::ranges::sort(a.begin(), a.end());
    std::ranges::sort(b.begin(), b.end());

    auto sum = std::transform_reduce(
      a.begin(), a.end(), b.begin(), 0ULL, std::plus<>(), 
      [](int x, int y) {return static_cast<size_t>(std::abs(x - y)); }  
    );
    fmt::println("The answer is {}", sum);
    return 0;
}