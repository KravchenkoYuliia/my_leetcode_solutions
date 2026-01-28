/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   030_substring_with_concatenation_of_all_words      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:26:22 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/28 12:48:51 by yukravch         ###   ########.fr       */
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
	
	static bool	findKey( unordered_map< string, int >&	wordsHashTable, string s ) {
	
		if ( wordsHashTable.find( s ) != wordsHashTable.end() &&
			wordsHashTable[ s ] != 0 )
				return true;
		return false;
	}

	static void	printHash( unordered_map< string, int >& wordsHashTable ) {

		for ( auto i : wordsHashTable ) 
			cout << i.first << " = " << i.second << endl;
	}

	static vector<int>	findSubstring(string s, vector<string>& words) {

		int	count = 1;
		vector<int>	result;
		int		start = 0;
		int		wordLength = words[ 0 ].size();

		unordered_map< string, int >	wordsHashTable;
		wordsHashTable = Solution::fillWordsHashTable( words );
		for ( int i = 0; i < s.size(); i++ ) {
			string	currentWord = s.substr( i, wordLength ); 
			cout << count << ". Current i = " << i << " word: " << currentWord << "    Hash Table status is " << endl;
			Solution::printHash( wordsHashTable );

			int j = i;
			while ( Solution::findKey( wordsHashTable, currentWord ) == true && j < s.size() ) {
				cout << " Found the word " << currentWord << " at the position " << j << "  need to check the next  words now in a loop" << endl;

				wordsHashTable[ currentWord ] -= 1;
				j += wordLength;
				string	currentWord = s.substr( j, wordLength ); 
			}
			
			cout << "After the loop " << endl;

			count++;
			cout << endl << endl;

		}


		return result;
	}
};


int	main( void ) {

	vector<string>	words = {"word","good","best","good"};
	vector<int>	result = Solution::findSubstring( "wordgoodgoodgoodbestword", words);

	for ( auto i : result )
		cout << i << ",";

	return 0;
}


/*
				if ( Solution::findKey( wordsHashTable, s.substr( i, wordLength ) ) == true ) {
					
					wordsHashTable[ s.substr( i, wordLength ) ] -= 1;
					cout << "word " << s.substr( i, wordLength )  << " -= 1 -->>> " << wordsHashTable[ s.substr( i, wordLength ) ] << endl;
					cout << " Found a word from words: " << s.substr( i, wordLength ) << endl;
				}
				else {

					cout << "word from s is not in words " << endl;
					wordsHashTable = Solution::fillWordsHashTable( words );
					cout << "start was " << start << endl;

						i = start;
						start += wordLength;
					cout << "start is now " << start << endl;


				}


				if ( Solution::allWordsAreUsed( wordsHashTable ) == true ) {
					
					cout << "hashTable has no more words " << endl;
					cout << "start was " << start << endl;
					result.push_back( start );
					i = start;
					start += wordLength;
					cout << "start is now " << start << endl;

					wordsHashTable = Solution::fillWordsHashTable( words );

*/
