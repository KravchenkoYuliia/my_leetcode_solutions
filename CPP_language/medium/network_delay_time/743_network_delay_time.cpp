/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   743_network_delay_time.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:27:14 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/23 11:19:28 by yukravch         ###   ########.fr       */
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

public:

	static int	networkDelayTime( vector< vector<int> >& times, int n, int k) {
	
		vector< vector< pair<int,int> > >	adj( n + 1 );
		vector< int >				distanceTable( n + 1 );
		priority_queue< pair< int,int > >	pq;

		for ( int i = 0; i < times.size(); i++ ) {
		
			adj[ times[i][0] ].push_back( make_pair( times[i][1], times[i][2] ) );
		}

		for ( int i = 0; i < distanceTable.size(); i++ ) {

			distanceTable[i] = INT_MAX;
		}
		distanceTable[k] = 0;

		pq.push( make_pair( 0, k ) );
		while ( !pq.empty() ) {
			int	currentNode = pq.top().second;
			int	currentDistance = pq.top().first;
			if ( currentDistance > distanceTable[ currentNode ])
				continue;
				
			pq.pop();
			
			for ( int i = 0; i < adj[currentNode].size(); i++ ) {
				int	neighborOfCurrentNode = adj[currentNode][i].first;
				int	delayTime = distanceTable[currentNode] + adj[currentNode][i].second;

				if ( delayTime < distanceTable[ neighborOfCurrentNode ] ) {
					distanceTable[ neighborOfCurrentNode ] = delayTime;
					pq.push( make_pair( distanceTable[ neighborOfCurrentNode ], neighborOfCurrentNode ) );
					
				}
			}
		}

		int	maxTime = 0;
		for ( int i = 1; i < distanceTable.size(); i++ ) {

			if ( maxTime < distanceTable[ i ] )
				maxTime = distanceTable[ i ];
		}

		if ( maxTime == INT_MAX )
			return -1;
		return maxTime;
	}
};

int	main( void ) {

	vector< vector<int> >	v = {

		{2,1,1},
		{2,3,1},
		{3,4,1}
	};
	
	int	result = Solution::networkDelayTime( v, 4, 2 );
	cout << "Result = " << result << std::endl;

	return 0;
}
