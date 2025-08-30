#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool    ft_compare_half(int x)
{
        int     half = 0;
        int     modulo = 0;

        while (x > half)
        {
                half *= 10;
                modulo = x % 10;
                x = x / 10;
                half += modulo;
                if (half == x || half / 10 == x)
                        return (true);
        }
        return (false);
}

bool isPalindrome(int x)
{
    if (x < 0)
        return (false);
    else if (x == 0)
            return (true);
    else if (x % 10 == 0)
            return (false);
    else
    {
        if (ft_compare_half(x))
                return (true);
        else
                return (false);
    }
}

int     main(int ac, char **av)
{
        if (ac != 2)
        {
                printf("One argument required\n");
                return (1);
        }
        int     test = atoi(av[1]);
        int result = isPalindrome(test);
        if (result == true)
                printf("true\n");
        else if (result == false)
                printf("false\n");
        return (0);
}
