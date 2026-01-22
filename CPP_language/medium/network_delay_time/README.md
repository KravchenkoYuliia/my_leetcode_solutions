## 1 Adjacency list
	
	the list of the neighbors for every node
	vector< vector<pair<int, int> > >  where pair is ( next node, time to arrive to this node )

	input:
		times -> [2,1,1]	=>	adj[1] = []
			[2,3,1]			adj[2] = [(1,1), (3,1)]
			[3,4,1]			adj[3] = [(4,1)]
						adj[4] = []


## 2 Table of the time distance

	vector<int>
	index = destination node  	and		the value is distance from the source node to the destination one

	initialization:
			index		distance
			1		INT_MAX
			2		0 ( source node )
			3		INT_MAX
			4		INT_MAX

## 3 Priority queue
	
	priority_queue< pair< int,int > >
	pair: minimal time to go from source node to the current node		and 		current node

	start: push ( 0, k ) to the queue because source node send the signal
		get the top value of the priority queue to check the neighbors of the current node

		current node is `2`
		take its neighbors from the adjacence list: `2` has `1` and `3` ( adj[2][0].first and adj[2][1].first )
		the signal from the `2` can is spreading to `1` and `3`
		calculate the distance to the them:
						new distanceTable[1] = distanceTable[2] + adj[2][0].second = 0 + 1 = 1;
						if this value < the actual distanceTable[1]: write it down 
						else: ignore
			
						new distanceTable[3] = 0 + 1 = 1
						1 < INT_MAX
						distanceTable[3] = 1

### 4 mark the node as visited after checking his heighbors

	vector< bool >
	
	node=index		status
	1			false
	2			visited
	3			false
	4			false


	push new candidants to the queue:
					1,`1`
					1,`3`
	take any node ( order is not important ) and repeate the same steps for `1` and `3` and so on
		if the node we take from the priority queue is already visited - ignore - top the next one
				
