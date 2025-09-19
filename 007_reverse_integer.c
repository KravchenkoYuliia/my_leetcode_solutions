#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648


int	ft_reverse_minus(int x)
{
	int	result = 0;


	while (x < 0)
	{
		if (result < INT_MIN/10)
			return 0;
		result *= 10;
		if (result < INT_MIN - x % 10)
			return 0;
		result += x % 10;
		x = x / 10;
	}

	return result;
}

int	ft_reverse_plus(int x)
{
	int	result = 0;

	while (x > 0)
	{
		if (result > INT_MAX/10)
			return 0;
		result *= 10;
		if (result > INT_MAX - x % 10)
			return 0;
		result += x % 10;
		x = x / 10;
	}

	return result;
}

int	ft_reverse(int x)
{

	if (x < 0)
		return ft_reverse_minus(x);
	if (x > 0)
		return ft_reverse_plus(x);
}

int	main(int ac, char** av)
{
	if (ac != 2)
		return 1;
	printf("%d\n", ft_reverse(atoi(av[1])));
}
