#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int     ft_strlen(char *str)
{
        int     i = 0;

        if (!str)
                return (0);
        while (str[i])
                i++;
        return i;
}

int     ft_strcmp(char **strs, int stop)
{
        int     i = 0;
        int     min = INT_MAX;


        while (i < stop && strs[i])
        {
                if (ft_strlen(strs[i]) < min)
                        min = ft_strlen(strs[i]);
                i++;
        }
        return (min);
}

void	ft_copy(char *dest, char *src, int stop)
{
	int	i = 0;

	while (i < stop && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char* longestCommonPrefix(char** strs, int strsSize)
{
        int     i = 0;
        int     word = 0;
        int     shortest_len;
        char    *result;

        shortest_len = ft_strcmp(strs, strsSize);
        result = calloc(shortest_len + 1, sizeof(char));
        if (!result)
                return (NULL);
        while (i <= shortest_len && strs[word] && strs[word][i])
        {
                while (word < strsSize && strs[word] && strs[word + 1])
                {
			printf("compare word %s with %s\ni = %d\nchar %c with char %c\n", strs[word], strs[word + 1], i, strs[word][i], strs[word+1][i]);
                        if (strs[word][i] == strs[word + 1][i])
			{
				word++;
				printf("if they re the same - next word, so compaer %s with %s\n", strs[word], strs[word + 1]);
			}
                        else
			{
				ft_copy(result, strs[0], i);
                                return (result);
			}
                        word++;
                }
                i++;
        }
        return (result);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	char *result;

	result = longestCommonPrefix(av + 1, ac - 1);
	printf("%s\n", result);
	free(result);
	return (0);
}
