## Hashing
	is a technique used in data structures that efficiently stores and retrieves data in a way that allows for quick access.
This algorithm is used in container like `std::unordered_map` and `std::unordered_set`

### unordered_set
	doubles are not possible

## solution
	s = {1,0,1,1}
	k = 1

	loop going on s elem by elem[


		window can only be k+1

		[1,0],1,1
		 1,[0,1],1
		 1,0,[1,1]
	
		 indices:
		 	0,1,2,3
			index 2 > k so if even  s[0]==s[2] it will not complete the condition  abs(i - j) <= k
					so we can erase nums[0] from set
		
		Example:
			index 0:
				is 0 > k? -> no
				is nums[0] (1) is already in set? -> no
				add nums[0] (1) to set

				set : 1
			index 1:	
				is 1 > k? -> no
				is nums[1] (0) is already in set? -> no
				add nums[1] (0) to set
				
				set : 1, 0
			index 2:	
				is 2 > k? -> yes
					rm from set nums[i-k-1]=nums[2-1-1]=nums[0]=1
					rm 1 from set
				set: 0
				is nums[2] (1) is already in set? -> no
				add nums[2] (1) to set
				
				set : 0, 1
			index 3:
			is 3 > k? -> yes
				rm from set nums[i-k-1]=nums[3-1-1]=nums[1]=0
				rm 0 from set
			set: 1
			is nums[3] (1) is already in set? -> yes -> return true because 
									abs(i-j) = 3-2 = 1
									1 <= k
									1 = 1
	]


