#include <iostream>
#include <array>
#include <fmt/core.h>
#include <numeric>
#include <unordered_map>

const int nb_lines = 1000;

// int get_frequency(int x, const std::array<int, nb_lines>& b)
// {
//     size_t freq = 0;
//     for(int i =0; i<nb_lines; i++)
//     {
//         if(x == b[i])
//         {
//             freq +=1;
//         }
//     }
//     return x*freq;
// }

int main()
{
    std::array<int, nb_lines> a;
    std::array<int, nb_lines> b;
    for(size_t i=0; i<nb_lines; i++)
    {
        if(!(std::cin >> a[i] >> b[i]))
        {
            fmt::println(stderr, "Error  reading output line {}", i+1);
            return 1;
        }
    }

    std::unordered_map<int, int> frequency_map;
    for(const int& value: b)
    {
        frequency_map[value]++;
    }

    auto sum = std::transform_reduce(
        a.begin(), a.end(), 0UL, std::plus<>(),
        [&frequency_map](int x) {
            auto it = frequency_map.find(x);
            return (it != frequency_map.end()) ? static_cast<size_t>(x * frequency_map[x]): 0UL;}
    );

    fmt::println("The answer is {}", sum);
    return 0;
}