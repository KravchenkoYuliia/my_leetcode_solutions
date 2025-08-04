#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	if (!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strdup(char *str)
{
	int i = 0;
	char *line = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!line)
		return (NULL);
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_strlen_n(int n)
{
	long int	len;
	long int	n_temp;

	len = 0;
	n_temp = n;
	if (n_temp < 0)
	{	
		len++;
		n_temp *= -1;
	}
	while (n_temp != 0)
	{
		n_temp /= 10;
		len++;
	}
	return (len);
}


char	*ft_itoa(int n)
{
	char		*array;
	long int	i;
	long int	n_temp;

	n_temp = n;
	i = ft_strlen_n(n);
	if (n == 0)
		return (ft_strdup("0"));
	array = (char *)calloc(ft_strlen_n(n) + 1, sizeof(char));
	if (!array)
		return (NULL);
	if (n_temp < 0)
		n_temp *= -1;
	while (i > 0)
	{
		array[i - 1] = n_temp % 10 + '0';
		n_temp /= 10;
		i--;
	}
	if (n < 0)
		array[i] = '-';
	return (array);
}

bool isPalindrome(int x)
{
	int start = 0;
	int end;
	int half_size;
	char	*str = ft_itoa(x);
	if (!str)
		return (false);
	end = ft_strlen(str);
	half_size = ft_strlen(str) / 2;
	while (str[start] && start < half_size)
	{
		while (str[end - 1] && end >= 0)
		{
			if (str[start] == str[end - 1])
			{
				end--;
				break ;
			}
			else
				return (false);
		}
		start++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("One argument required\n");
		return (1);
	}
	int	test = atoi(av[1]);
	int result = isPalindrome(test);
	if (result == true)	
		printf("true\n");
	else if (result == false)
		printf("false\n");
	return (0);
}
