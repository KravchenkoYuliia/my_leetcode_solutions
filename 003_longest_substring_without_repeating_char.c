#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s)
{
    
}

int	main(int ac, char** av)
{
	if (ac != 2)
		return 1;

	int result = lengthOfLongestSubstring(av[1]);
	printf("%d\n", result);
}
