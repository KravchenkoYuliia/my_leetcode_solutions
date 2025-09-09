#include <stdio.h>
#include <stdlib.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	double	last;
	int	total_index = -1;
	int	stop_index;
	int	i = 0;
	int	j = 0;
	int	type = 0;


	if ((nums1Size + nums2Size) % 2 == 0)
		type = 0;
	else
		type = 1;
	stop_index = (nums1Size + nums2Size) / 2;
	while (total_index != stop_index)
	{
		
		if (i < nums1Size && (j >= nums2Size || (nums2Size != 0 && nums1[i] <= nums2[j])))
		{
			total_index++;
			if (type == 1 && total_index == stop_index)
				return nums1[i];
			if (type == 0 && total_index == stop_index)
				return ((last + nums1[i]) / 2);
			last = (double)nums1[i];
			i++;
		}
		else if (j < nums2Size && (i >= nums1Size || (nums1Size != 0 && nums1[i] > nums2[j])))
		{
			total_index++;
			if (type == 1 && total_index == stop_index)
				return nums2[j];
			if (type == 0 && total_index == stop_index)
				return ((last + (double)nums2[j]) / (double)2);
			last = (double)nums2[j];
			j++;
		}
	}

	return (0);
}

int	main()
{
	int	nums1[] = {1, 8};
	int	nums2[] = {3,9};

	double	result = findMedianSortedArrays(nums1, 2, nums2, 2);
	printf("%f\n", result);
}
