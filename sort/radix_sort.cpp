#include <iostream>
#include <vector>

int step = 1;
void print(const std::vector<int> &val)
{
    std::cout << "\nStep " << step << "\nValues => ";
    step++;
    for (auto &i : val)
    {
        std::cout << i << ", ";
    }
}

void printDigit(const std::vector<std::vector<int>> &dig)
{
    std::cout << "\nSorted => ";
    for (auto &i : dig)
    {
        for (auto &j : i)
        {
            std::cout << j << ", ";
        }
    }
}

void radix_sort(std::vector<int> &val, std::vector<std::vector<int>> &dig)
{
    bool digit_control = true;
    int pw = 1;
    while (digit_control)
    {

        if (pw > 1)
        {
            bool a = false;
            for (size_t i = 0; i < val.size(); i++)
            {
                if (0 != (val[i] / pw))
                {
                    a = true;
                }
            }
            if (!a)
            {
                break;
            }
        }

        for (int i = 0; i < val.size(); i++)
        {
            dig[(val[i] / pw) % 10].push_back(val[i]);
        }

        val.clear();

        for (size_t i = 0; i < dig.size(); i++)
        {
            for (size_t j = 0; j < dig[i].size(); j++)
            {
                val.push_back(dig[i][j]);
            }
        }

        print(val);
        printDigit(dig);
        for (auto &i : dig)
        {
            i.clear();
        }

        pw *= 10;
    }
}

int main()
{

    std::vector<int> values{40, 615, 19, 66,
                            8932239, 1545, 37, 75,
                            31, 94, 33265, 32,
                            611, 651318, 43, 81,
                            564, 987, 13, 2, 678};


    std::vector<std::vector<int>> digits{};
    digits.resize(10);

    radix_sort(values, digits);
}
