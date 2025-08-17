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
        return (-1);
}

bool isValid(char* s)
{
        int     i;
        int     j;
	char	stack[1000];

        i = 0;
	j = 0;
        while (s[i])
        {
        	if (!ft_open_or_close(s[i]) || ft_open_or_close(s[i]) == -1)
                	return (false);
		while (ft_open_or_close(s[i]) == 1)
		{	
			if (s[i] == '(')
				stack[j] = ')';
			else if (s[i] == '{')
				stack[j] = '}';
			else if (s[i] == '[')
				stack[j] = ']';
			i++;
			j++;
		}
		stack[j] = '\0';
		if (ft_open_or_close(s[i]) != 0)
			return (false);
		j--;
		while (ft_open_or_close(s[i]) == 0 && j >= 0)
		{
			if (s[i] != stack[j])
				return (false);
			stack[j] = '\0';
			i++;
			j--;
		}
		if (j > -1 && stack[j] != '\0')
			return (false);
		j = 0;
        }
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
