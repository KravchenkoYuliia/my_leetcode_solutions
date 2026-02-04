/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   219_contains_duplicate_II.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:30:29 by yukravch          #+#    #+#             */
/*   Updated: 2026/02/04 17:43:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <unordered_set> 
#include <vector>

using namespace std;

class Solution {
public:
    static bool	containsNearbyDuplicate(vector<int>& nums, int k) {

	unordered_set<int>	set;

	for ( int i = 0; i < nums.size(); i++ ) {

		if ( i > k )
			set.erase( nums[i - k - 1] );

		if ( set.count( nums[ i ] ) )
			return true;
		
		set.insert( nums[ i ] );
	}

	    return false;
    }
};

int	main( void ) {

	vector<int> 	v = {1,2,3,1,2,3};
	int		k = 2;

	bool	result = Solution::containsNearbyDuplicate( v, k );
	if ( result == 1 )
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}
