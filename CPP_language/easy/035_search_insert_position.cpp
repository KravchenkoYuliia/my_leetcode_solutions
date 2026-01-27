/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   035_search_insert_position.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:48:45 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/27 13:20:15 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector> 

using namespace std;


class Solution {

public:
	static int searchInsert(vector< int >& nums, int target) {

		int	size = nums.size();
		int	min = 0;
		int 	max = size - 1;
		int	index;
		
		while ( min <= max ) {
			
			index = min + ( max-min )/2;
			if ( nums[ index ] == target )
				return index;

			else if ( nums[ index ] < target )
				min = index + 1;
			else if ( nums[ index ] > target )
				max = index - 1;
		}
	

		return min;
	}
};



int	main( int ac, char** av ) {

	if ( ac != 3 ) {

		cerr << "Give a list of integers and 1 integer to be inserted to this list. " << "all nmbers are sorted and are less than 10 " << endl << " Exemple: " << endl << "./a.out \"1 3 4 5 9\"  5" << endl;
		return 1;
	}

	vector< int >	v;
	for ( int i = 0; av[1][i]; i++ ) {

		if ( isdigit( av[1][i] ))
			v.push_back( av[1][i] - '0' );
	}
	int result = Solution::searchInsert( v, atoi(av[2]) );
	cout << "Result : " << result << endl;
	return 0;
}
