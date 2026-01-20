#include <stdio.h>
#include <stdlib.h>


int	ft_check_double(char* s, char to_check, int current)
{
	while (current > 0)
	{

		if (to_check == s[current-1])
			return 1;
		current--;
	}
	return 0;
}

int	ft_result_from_current_substring(char* s)
{
	int	i = 0;
	int	count = 0;
	
	while (s[i])
	{
		if (ft_check_double(s, s[i], i) == 1)
			return count;
		i++;
		count++;
	}

	return count;
}

int lengthOfLongestSubstring(char* s)
{
	int	i = 0;
	int	result = 0;
	int	substring_result;

	while (s[i])
	{
		substring_result = ft_result_from_current_substring(&s[i]);
		if (substring_result > result)
			result = substring_result;
		i++;
	}

	return result;

}

int	main(int ac, char** av)
{
	if (ac != 2)
		return 1;

	int result = lengthOfLongestSubstring(av[1]);
	printf("%d\n", result);
}
