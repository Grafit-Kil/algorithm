#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

template <typename T>
T average(const std::vector<T> &set)
{
    T m = std::accumulate(set.begin(), set.end(), 0.0) / set.size();
    return m;
}

template <typename T>
T variance(const std::vector<T> &set, T avg)
{

    T v{};
    for (auto i : set)
    {
        v += std::pow((i - avg), 2);
    }

    return v / set.size();
}

template <typename T>
auto standard_deviation(T varyans)
{

    return std::sqrt(varyans);
}

int main()
{
    std::vector<double> dataset{24.7, 53.4, 7.58, 59.9, 95.3, 35.3,
                                11.9, 66.1, 2.67, 97.8, 12.8, 36.6,
                                13.1, 95.6, 3.09, 36.3, 73.2, 87.2,
                                99.1, 87.6, 2.05, 48.9, 23.6, 47.8,
                                40.4, 74.3, 4.58, 21.6, 69.0, 84.1,
                                71.7, 15.1, 4.46, 29.3, 99.2, 30.1,
                                47.5, 87.4, 8.55, 65.6, 97.9, 74.1,
                                28.9, 32.7, 3.6, 257.5, 61.8, 84.2,
                                34.9, 43.4, 35.5, 618.3, 13, 35.51,
                                71.7, 15.1, 4.46, 29.3, 99.2, 30.1};

    auto avg = average(dataset);
    auto var = variance(dataset, avg);
    auto std_dev = standard_deviation(var);
    std::cout << "average = " << avg << "\n"
              << "variance = " << var << "\n"
              << "standard_deviation = " << std_dev << "\n";
}
