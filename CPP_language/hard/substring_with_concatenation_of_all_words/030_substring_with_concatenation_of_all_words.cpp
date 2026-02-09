/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   030_substring_with_concatenation_of_all_words      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:26:22 by yukravch          #+#    #+#             */
/*   Updated: 2026/02/04 13:59:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static unordered_map< string, int > 	fillWordsHashTable( vector<string>& words ) {

		unordered_map< string, int > newHash;
		
		for ( int i = 0; i < words.size(); i++ ) {

			newHash[ words[ i ]] += 1;
		}
		return newHash;
	}

	static bool	allWordsAreUsed( unordered_map< string, int >&	wordsHashTable ) {

		for ( auto key : wordsHashTable )
			if ( key.second > 0 ) {  return false;  }
		return true;
	}
	
	static bool	findKey( unordered_map< string, int >&	wordsHashTable, string& s ) {
	
		if ( wordsHashTable.find( s ) == wordsHashTable.end() )
			return false;
		if ( wordsHashTable[ s ] == 0 )
				return false;
		return true;
	}

	static void	printHash( unordered_map< string, int >& wordsHashTable ) {

		for ( auto i : wordsHashTable ) 
			cout << i.first << " = " << i.second << endl;
	}

	//MAIN FUNCTION
	static vector<int>	findSubstring(string s, vector<string>& words) {

		vector<int>	result;
		
		if ( s == "" || words.empty() )
			return result;
		
		int		start = 0;
		int		wordLength = words[ 0 ].size();

		int		sSize = s.size();
		int		lengthAllWordsTogether = words.size() * wordLength;

		unordered_map< string, int >	wordsHashTable;
		for ( auto w : words )
			wordsHashTable[ w ]++;
		//wordsHashTable = Solution::fillWordsHashTable( words );
		for ( int i = 0; i < wordLength; i++ ) {
			
			unordered_map< string, int > window;
			int left = 
			if ( sSize - i < lengthAllWordsTogether )
				return result;

			string	currentWord = s.substr( i, wordLength );
		
			int j = i;
			while ( Solution::findKey( wordsHashTable, currentWord ) == true && j < sSize ) {
				
				wordsHashTable[ currentWord ] -= 1;
				j += wordLength;
				currentWord = s.substr( j, wordLength );

				if ( Solution::allWordsAreUsed( wordsHashTable ) == true ) {
					result.push_back( start );
					break ;
				}
			}
			
			
			wordsHashTable = Solution::fillWordsHashTable( words );
			start += 1;
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
