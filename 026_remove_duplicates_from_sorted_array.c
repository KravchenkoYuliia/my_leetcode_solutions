#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_duplicates(int* nums, int numsSize, int check)
{
	int	i = check + 1;

	while (i < numsSize)
	{
		if (nums[i] == nums[check])
			return true;
		i++;
	}

	return false;
}

int removeDuplicates(int* nums, int numsSize)
{
	int	check = 0;
	int	write = 0;

	while (check < numsSize)
	{
		if (ft_duplicates(nums, numsSize, check) == false)
		{
			nums[write] = nums[check];
			write++;
		}
		check++;
	}

	return write;
}

int	main()
{
	int	nums[13] = {1, 1, 3, 3, 4, 4, 4, 4, 6, 7, 8, 9, 9};

	int	result = removeDuplicates(nums, 13);
	int	i = 0;

	printf("[");
	while (i < result)
	{
		printf("%d", nums[i]);
		i++;
	}
	printf("]\n");
	return 0;
}
