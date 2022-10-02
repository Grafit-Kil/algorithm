#include <stdio.h>
#include <math.h>

int main()
{

    int max_value = 1000;

    for (int i = 2; i < max_value; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i == j)
            {
                printf("%i\n", i);
            }

            if (i % j == 0)
            {
                break;
            }
        }
    }
    return 0;
}