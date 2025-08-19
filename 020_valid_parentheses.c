#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define CLOSE 0
#define OPEN 1
#define ERROR -1

int     ft_open_or_close(char c)
{
        if (c == '(' || c == '{' || c == '[')
                return (OPEN);
        else if (c == ')' || c == '}' || c == ']')
                return (CLOSE);
        return (ERROR);
}

bool isValid(char* s)
{
        int     i;
        int     j;
	char	stack[100000];

        i = 0;
	j = 0;
        while (s[i])
        {
		if (ft_open_or_close(s[i]) == OPEN)
		{	
			if (s[i] == '(')
				stack[j] = ')';
			else if (s[i] == '{')
				stack[j] = '}';
			else if (s[i] == '[')
				stack[j] = ']';
			j++;
		}
		else if (ft_open_or_close(s[i]) == CLOSE)
		{
			if (j == 0 || s[i] != stack[j - 1])
				return (false);
			j--;
		}
		else if (ft_open_or_close(s[i]) == ERROR)
			return (false);
		i++;
        }
	if (j > 0)
		return (false);
        return (true);
}

int     main(int ac, char **av)
{
        if (ac != 2)
                return (1);
        if (isValid(av[1]))
                printf("true\n");
        else
                printf("false\n");
        return (0);
}
