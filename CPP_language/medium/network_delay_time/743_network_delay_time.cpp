/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   743_network_delay_time.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:27:14 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/22 14:27:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
 
/*
n -> how many nodes
k -> source node - from where the signal is send
*/

using namespace std;
class Solution {

public:// TEMP METHODS
	/*static void		printVectorOfVector( vector< vector<int> >& v ) {
			
		for ( int i = 0; i < v.size(); i++ ) {
			
			std::cout << "[";
			for ( int j = 0; j < v[i].size(); j++ ) {
				
				std::cout << v[i][j];
				if ( j < v[i].size() - 1 )
					std::cout << ",";
			}
			std::cout << "]" << std::endl;
		}

	}
	*/
	/*static void	printAdjacencyList( vector< vector< pair<int,int> > >&  adj ) {

		for ( int i = 0; i < adj.size(); i++ ) {

			cout << "adj[" << i << "]";
			if ( adj[i].empty() ) {
				cout << "()" << endl;
			}
			else {
			
				for ( int j = 0; j < adj[i].size(); j++ ) {

					cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")";
				}
				cout << endl;
			}
		
		}
	}*/
	/*
	static void	printDistanceTable( vector< int >& v ) {

		for ( int i = 0; i < v.size(); i++ ) {

			cout << "from source to the node [" << i << "]: " << v[i] << endl; 
		}
	}
	*/
	static void	makeAdjacencyList( vector< vector< pair<int,int> > >&  adj, vector< vector<int> >& v ) {

		for ( int i = 0; i < v.size(); i++ ) {
		
				adj[ v[i][0] ].push_back( make_pair( v[i][1], v[i][2] ) );
		}
		
	}

	static void	makeDistanceTable( vector< int >& distanceTable, int k ) {

		for ( int i = 0; i < distanceTable.size(); i++ ) {

			distanceTable[i] = INT_MAX;
		}
		distanceTable[k] = 0;
	}

	static int	networkDelayTime( vector< vector<int> >& times, int n, int k) {
	
		vector< vector< pair<int,int> > >	adj( n + 1 );
		vector< int >				distanceTable( n + 1 );
		priority_queue< pair< int,int > >	pq;

		Solution::makeAdjacencyList( adj, times );
		Solution::makeDistanceTable( distanceTable, k );
		
		pq.push( make_pair( 0, k ) );
		cout << pq.top().first << " and " << pq.top().second;
		
		return -1;
	}


};

int	main( void ) {

	vector< vector<int> >	v = {
		{2,1,1},
		{2,3,1},
		{3,4,1}
	};
	
	int	result = Solution::networkDelayTime( v, 4, 2 );
	//cout << "Result = " << result << std::endl;

	return 0;
}

