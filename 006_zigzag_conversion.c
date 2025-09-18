#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*	ft_convert(char* s, int numRows)
{
	int	i = 0;
	int	j = 1;
	int     pattern;
	char*	result;
       
	result	= calloc(strlen(s) + 1, sizeof(char));
	if (!result)
		return NULL;

	pattern = numRows * 2 - 2; // pattern for the first and the last line of zigzag
	
	result[0] = s[0];
	while (i < 3)
	{
		result[i+1] = s[i+pattern];
		i++;
	}
	return result;
}

int	main(int ac, char** av)
{
	if (ac != 3)
		return 1;
	char* result = ft_convert(av[1], atoi(av[2]));
	printf("%s\n", result);
}
