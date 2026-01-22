/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   008_string_to_integer_atoi.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:42:54 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/22 13:43:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <climits> 
using namespace std;

class	Solution {
public:
	static int myAtoi(string s) {

		int	i = 0;
		int	sign = 1;
		long	result = 0;

		while ( i < s.size() && isspace(s[i]) )
			i++;
	
		if ( i < s.size() && ( s[i] == '-' || s[i] == '+' ) ) {  
			if ( s[i] == '-' )
				sign = -1;
			i++;
		}
		
		while ( i < s.size() && (s[i] >= '0' && s[i] <= '9') ) {

			result *= 10;
			if ( result * sign < INT_MIN || result * sign > INT_MAX ) {

				if ( sign < 0)
					return INT_MIN;
				else
					return INT_MAX;
			}

			result += s[i] - '0';
			if ( result * sign < INT_MIN || result * sign > INT_MAX ) {
				if ( sign < 0)
					return INT_MIN;
				else
					return INT_MAX;
			}

			i++;
		}

		return result * sign;
	}
};


int	main( int ac, char** av ) {

	if ( ac != 2 ) {
		std::cerr << "./a.out \"32132144(any integer string to convert)\"" << std::endl;
		return 1;
	}

	int result = Solution::myAtoi( av[1] );
	std::cout << "Result: " << result << std::endl;

	return 0;
}
