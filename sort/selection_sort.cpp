#include <iostream>
#include <array>
#include <utility>

#define LENGTH 20

template <std::size_t SIZE>
void printArr(const std::array<int, SIZE> &cArr)
{
    for (auto &element : cArr)
    {
        std::cout << element << ", ";
    }
}

template <std::size_t SIZE>
void sortArr(std::array<int, SIZE> &cArr)
{
    int index{0};

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            if (cArr[index] > cArr[j])
            {
                std::swap(cArr[index], cArr[j]);
                std::cout << "\n" << cArr[index] <<" swap "<< cArr[j] << "\n";
                printArr(cArr);
            }
        }
        index++;
    }
}

int main()
{
    std::array<int, LENGTH> arr{4, 65, 17, 66,
                                89, 145, 37, 7,
                                31, 9, 65, 32,
                                1, 68, 43, 81,
                                74, 12, 68, 43};

    printArr(arr);
    sortArr(arr);

}