#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_rom_to_int(char c)
{
	int	i;

	i = 0;
	switch (c)
	{
		case 'I':
			i = 1;	
			break;
		case 'V':
			i = 5;
			break;
		case 'X':
			i = 10;
			break;
		case 'L':
			i = 50;
			break;
		case 'C':
			i = 100;
			break;
		case 'D':
			i = 500;
			break;
		case 'M':
			i = 1000;
			break;
	}
	return (i);
}
int romanToInt(char* s)
{
	int	i;
	int	current;
	int	next;
	int	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		current = ft_rom_to_int(s[i]);
		if (s[i + 1])
			next = ft_rom_to_int(s[i + 1]);
		else
			next = 0;
		if (current < next)
			result -= current;
		else if (current >= next)
			result += current;
		i++;
	}
	return (result);


}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Write one argument, please\n");
		return (1);
	}
	int i = romanToInt(av[1]);
	printf("int value from %s is %d\n", av[1], i);
	return (0);
}
