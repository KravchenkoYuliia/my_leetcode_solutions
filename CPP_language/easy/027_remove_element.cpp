/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   027_remove_element.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:08:17 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/20 15:48:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <vector>

using namespace std;
class Solution {
public:

	void	swap_with_the_last_elem( vector<int>& nums, int i, int& vector_size, int& result ) {


		while ( vector_size > 0 && nums[vector_size - 1] == nums[i] )
			vector_size--;
		int	last_i = vector_size - 1;
		if ( last_i == i )
			return ;
		if ( i < vector_size && last_i < vector_size ) {

			swap( nums[i], nums[last_i] );
			vector_size -= 1;
			result += 1;
		}
	}

	int	removeElement(vector<int>& nums, int val) {

		int	result  = 0;
	    	int	vector_size = nums.size();

	    for ( int i = 0; i < vector_size; i++ ) {
		    
		    if ( nums[i] == val ) {
			    swap_with_the_last_elem( nums, i, vector_size, result );
		    }
		    else
			    result += 1;
	    }
	    return result;
    }
};

int	main(int ac, char** av) {

	if ( ac != 3 ) {

		std::cerr << "Write 2 arguments: numbers less than 10 separated by coma(without spaces) and a value to remove. For exemple:" << std::endl << "./a.out \"1,2,2,2,0,8,5,5\" 2 " << std::endl;
		return 1;
	}

	vector<int>	nums;
	for ( int i = 0; av[1][i]; i++ ) {

		if ( av[1][i] != ',' ) {
			nums.push_back( av[1][i] - '0' );
		}
	}
	
	if ( av[2][0] && av[2][1] ) { 
		std::cerr << "Wrong value to remove " << std::endl;
	}

	Solution	obj;
	int	result = obj.removeElement( nums, atoi( av[2] ) );


	std::cout << "Now vector is ";
	for ( int i = 0; i < nums.size(); i++ ) {
		std::cout << nums[i];
		if ( i != nums.size() - 1 )
			std::cout << ",";
	}
	std::cout << std::endl;

	std::cout << "Result = " << result << std::endl;
	return 0;
}
