/*Two Sum
https://leetcode.com/problems/two-sum/description/
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *res = malloc(sizeof(int) * 3);
    if (!res)
        return (NULL);
    
    int i = 0;
    int j;
    while (i < numsSize)
    {
        j = 0;
        while (j < numsSize)
        {
            if (i == j)
                break ;
            else if (nums[i] + nums[j] == target)
                {
                    res[0] = i;
                    res[1] = j;
                    *returnSize = 2;
                    return (res);
                }
            j++;
        }
        i++;
    }
    returnSize = 0;
    return (NULL);
}

int	main()
{
	int	nums[4] = {2, 9, 1, 4};
	int	numsSize = 4;
	int	target = 13;
	int	returnSize = 0;
	int	*finalRes = twoSum(nums, numsSize, target, &returnSize);
	printf("[%d %d]\n", finalRes[0], finalRes[1]);
}
