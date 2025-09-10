#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_len(char* s)
{
	int	i = 0;

	if (!s)
		return 0;
	while (s[i])
		i++;
	return i;
}

void	ft_strcpy(char* dest, char* src, int stop)
{
	int	i = 0;

	while (i <= stop)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_palindrome_or_not(char* s, int stop)
{
	int	start = 0;
	int	end = stop;
	int	half = stop / 2;

	while (start <= half)
	{
		if (s[start] != s[end])
			return 0;
		end--;
		start++;
	}

	return 1;
}

void	ft_get_palindrome(char* s, char* buffer)
{
	int	i = 0;
	int	j = ft_len(s)-1;

	while (j >= i)
	{
		if (ft_palindrome_or_not(s, j) == 1)
		{
			ft_strcpy(buffer, s, j);
			return ;
		}
		j--;
	}
	return ;
}

char* longestPalindrome(char* s)
{
	int	i = 0;
	char*	result;
	char*	buffer;

	result = calloc(ft_len(s)+1, sizeof(char));
	if (!result)
		return NULL;
	buffer = calloc(ft_len(s)+1, sizeof(char));
	if (!buffer)
		return NULL;

	while (s[i])
	{
		ft_get_palindrome(&s[i], buffer);
		if (ft_len(buffer) > ft_len(result))
			ft_strcpy(result, buffer, ft_len(buffer));
		i++;
	}
	free(buffer);
	if (!result)
		return NULL;
	return result;
}

int	main(int ac, char** av)
{
	if (ac != 2)
		return 1;

	char*	result = NULL;
	result = longestPalindrome(av[1]);
	if (!result)
		return 0;
	printf("%s\n", result);
	free(result);
    	return 0;
}
