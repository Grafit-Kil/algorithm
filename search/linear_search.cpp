#include <iostream>
#include <vector>

bool linear_search(std::vector<int> &arr, int val)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> arr{4, 65, 17, 66,
                            89, 145, 37, 7,
                            31, 9, 65, 32,
                            1, 68, 43, 81,
                            74, 12, 68, 43};
    std::cout << std::boolalpha;
    std::cout << linear_search(arr, 52) << "\n";
    std::cout << linear_search(arr, 12) << "\n";
    std::cout << linear_search(arr, 68) << "\n";
    std::cout << linear_search(arr, 74) << "\n";
}