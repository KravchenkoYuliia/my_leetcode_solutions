/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   028_find_the_index_of_the_first_occurence_in_      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:35:28 by yukravch          #+#    #+#             */
/*   Updated: 2026/02/11 15:28:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Solution {
public:
    static int		strStr( string haystack, string needle ) {
	
	    int	needleSize = needle.size();
	    
		for ( int i = 0; i < haystack.size(); i++ ) {
			
			if ( haystack[ i ] == needle[ 0 ] ) {

				int start = i;
				int stop = start + needleSize;

				for ( int j = 0; j < needleSize; j++ ) {

					if ( start < stop && haystack[ start ] != needle[ j ] )
						break;
					if ( start == stop - 1 )
						return i;
					start++;
				}

			}
		}
	   

        return -1;
    }
};


int	main( int ac, char** av ) {

	if ( ac != 3 ) {  cerr << "./a.out \"where\" \"what\"" << endl; return 1;  }

	cout << Solution::strStr( av[1], av[2] ) << endl;

	return 0;
}
