#include <iostream>
#include <vector>
#include <algorithm>

bool binary_search(const std::vector<int> &arr, const int val)
{
    int max_index{static_cast<int>(arr.size()) - 1};
    int min_index{0};

    if (arr[min_index] > val || arr[max_index] < val)
    {
        return false;
    }

    int range;
    while (1)
    {

        if (val == arr[max_index] || val == arr[min_index])
            return true;

        if (max_index == min_index - 1 || max_index == min_index + 1)
            return false;

        range = max_index - min_index;

        if (val < arr[max_index - range / 2])
        {

            max_index -= range / 2;
        }
        else
        {
            if ((range / 2) % 2 == 0)
            {
                min_index += range / 2 - 1;
            }
            else
            {
                min_index += range / 2;
            }
        }
    }
}

int main()
{
    std::vector<int> arr{4, 65, -17, 66,
                         89, 14, 37, 7,
                         31, -9, 65, 32,
                         1, -68, 43, 81,
                         74, 12, 68, 43};

    std::sort(arr.begin(), arr.end());

    for (auto &&i : arr)
    {
        std::cout << i << " - ";
    }

    std::cout << std::boolalpha << "\n";

    for (int i = -100; i < 100; i++)
        if (binary_search(arr, i))
            std::cout << i << " == true\n";
}