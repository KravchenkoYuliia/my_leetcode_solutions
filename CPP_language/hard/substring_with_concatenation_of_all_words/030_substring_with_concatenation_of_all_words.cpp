/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   030_substring_with_concatenation_of_all_words      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:26:22 by yukravch          #+#    #+#             */
/*   Updated: 2026/02/10 11:47:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

	static void	printHash( unordered_map< string, int >& wordsHashTable ) {

		for ( auto i : wordsHashTable ) 
			cout << i.first << " = " << i.second << endl;
	}

	//MAIN FUNCTION
	static vector<int>	findSubstring(string s, vector<string>& words) {

		vector<int>	result;
		
		if ( s == "" || words.empty() )
			return result;
		
		int		wordLength = words[ 0 ].size();

		int		sSize = s.size();
		int		howManyWords = words.size();
		int		lengthAllWordsTogether = howManyWords * wordLength;

		unordered_map< string, int >	wordsHashTable;
		for ( auto w : words )
			wordsHashTable[ w ]++;
		

		for ( int i = 0; i < wordLength; i++ ) {
		
			unordered_map< string, int >	window;
			int				start = i;
			int				countFoundWords = 0;

			for ( int stop = i; stop + wordLength <= sSize; stop += wordLength ) {

				string	currentWord = s.substr( stop, wordLength );

				if ( wordsHashTable[ currentWord ] ) {

					window[ currentWord ] += 1;
					countFoundWords += 1;

					while ( window[ currentWord ] > wordsHashTable[ currentWord ] ) {
						//delete the from window that is the most on the left in s = first added word to window
						window[ s.substr( start, wordLength ) ] -= 1;
						countFoundWords -= 1;

						start += wordLength;
					}
					
					if ( countFoundWords == howManyWords )
						result.push_back( start );
				}
				else {
					window.clear();
					countFoundWords = 0;
					start = stop + wordLength;
				}
			}
		}
		return result;
	}
};

int	main( void ) {

	vector<string>	words = {"bar","foo","the"};
		vector<int>	result = Solution::findSubstring( "barfoofoobarthefoobarman", words);

	for ( auto i : result )
		cout << i << ",";

	return 0;
}
