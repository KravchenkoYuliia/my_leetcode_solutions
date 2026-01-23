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
			-------------------------------
			1		INT_MAX
			2		0 ( source node )
			3		INT_MAX
			4		INT_MAX

## 3 Priority queue
	
	priority_queue< pair< int,int > >
	pair: minimal time to go from source node to the current node		and 		current node

	start: push ( 0, k ) to the queue because source node send the signal
		get the top value of the priority queue to check the neighbors of the current node

		current node is `k=2`
		take its neighbors from the adjacence list: `2` has `1` and `3` ( adj[2][0].first and adj[2][1].first )
		the signal from the `2` is spreading to `1` and to `3`
		calculate the distance to them:
						new distanceTable[1] = distanceTable[2] + adj[2][0].second = 0 + 1 = 1;
						if this value < the actual distanceTable[1]: write it down 
						else: ignore
			
						new distanceTable[3] = 0 + 1 = 1
						1 < INT_MAX
						distanceTable[3] = 1

push new candidants to the queue:
				1,`1`
				1,`3`
take any node ( order is not important ) and repeate the same steps for `1` and `3` and so on
		if the node we take from the priority queue is already visited - ignore - top the next one

### 4 mark the node as visited after checking his heighbors

	vector< bool >
	
	node=index		status
	--------------------------------
	1			false
	2			visited
	3			false
	4			false


nput: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

## TEST
### 1
	vectors:{2,1,1},
		{2,3,1},
		{3,4,1}
	n = 4
	k = 2

	Expected result : 2
### 2
	vectors:{1,2,1}
	n = 2
	k = 1

	Expected result: 1

### 3
	vectors:{1,2,1}
	n = 2
	k = 2
	
	Expected result: -1

### 4
	vectors:{1,2,1},
		{2,1,3}
	n = 2
	k = 2
	
	Expected result: 3

### 5
	vectors:{{4,2,76},
	{1,3,79},
	{3,1,81},
	{4,3,30},
	{2,1,47},
	{1,5,61},
	{1,4,99},
	{3,4,68},
	{3,5,46},
	{4,1,6},
	{5,4,7},
	{5,3,44},
	{4,5,19},
	{2,3,13},
	{3,2,18},
	{1,2,0},
	{5,1,25},
	{2,5,58},
	{2,4,77},
	{5,2,74}}

	n = 5
	k = 3
	
	Expected result: 59

