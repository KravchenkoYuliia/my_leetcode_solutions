#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	ft_strlen(char* s)
{
	int	i = 0;
	int	count = 0;

	if (!s)
		return 0;
	while (s[i])
	{
		if (s[i] != 32)
			count++;
		i++;
	}
	return count;
}

int lengthOfLastWord(char* s)
{
	int	len = strlen(s) -1;

	while (len > 0 && s[len] == 32) //spaces
		len--;
	while (len > 0 && s[len] != 32) //last word
		len--;
	return ft_strlen(&s[len]);
}

int main(int ac, char** av)
{
	if (ac != 2)
		return 1;

	int	i = lengthOfLastWord(av[1]);

	printf("length of last word is %d\n", i);
}
