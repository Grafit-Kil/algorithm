#include <iostream>
#include <cmath>
#include <cassert>


typedef unsigned long int ULLI;


int main()
{

    constexpr int decimal_place{3};
    constexpr int begin_digit{5};

    assert(decimal_place > 0 && "Divide by zero!");
    assert(begin_digit > 0 && "It must start with a NON-zero number!");

    auto divisible = [](const ULLI &x) -> bool
    {
        for (ULLI i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    };

    for (ULLI value{static_cast<ULLI>(pow(10, decimal_place - 1) * begin_digit)};
         value < static_cast<ULLI>(pow(10, decimal_place - 1) * (begin_digit + 1));
         value++)
    {
        if (value >= (pow(10, decimal_place - 1)) && divisible(value))
        {
        std::cout << value <<"\n";
            
        }
    }
    return 0;
}