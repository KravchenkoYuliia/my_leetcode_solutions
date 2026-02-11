/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   011_container_with_most_water.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:43:08 by yukravch          #+#    #+#             */
/*   Updated: 2026/02/11 15:43:08 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int maxArea( vector< int >& height ) {
     
	    for ( int i = 0; i < height.size(); i++ )
		    cout << height[i] << endl;
    	return -1;
    }
};

int	main( int ac, char** av ) {

	if ( ac != 2 ) {
		cerr << "Write 1 arg with heights separated by spaces" << endl;
		return 1;
	}

	vector< int >	height;
	for ( int i = 0; av[1][i]; i++ ) {

		if ( av[1][i] != ' ')
			height.push_back( av[1][i] - '0' );
	}

	cout << Solution::maxArea( height ) << endl;
	return 0;
}
