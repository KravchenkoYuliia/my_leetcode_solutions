#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	static vector<vector<int>>	threeSum( vector<int>& nums ) {
	
		int	size = nums.size();
		vector<vector<int>>	result;

		sort( nums.begin(), nums.end() );
		for ( size_t i = 0; i < size; i++ ) {
			
			if (i > 0 && nums[i] == nums[i-1]) {
		                continue;
			}
			int j = i+1;
			int k = size-1;

			while ( j < k ) {
				int sum = nums[i] + nums[j] + nums[k];
				if ( sum == 0 ) {
					result.push_back( {{nums[i], nums[j], nums[k]}} );
					j++;
					k--;
					while ( j < k && nums[j] == nums[j-1] )
						j++;
				}
				else if ( sum < 0 ) {
					if ( j + 1 < size && nums[j+1] == nums[j] )
						j += 2;
					else
						j += 1;
				}
				else {
					if ( k - 1 > i && nums[k-1] == nums[k] )
						k -= 2;
					else
						k--;
				}
			}
		}

		return result;
	}
};

int	main() {

	vector<int>		nums   = {-1,0,1,2,-1,-4, 2};
	vector<vector<int>>	result = Solution::threeSum( nums );

	cout << "result:" << endl;
	for ( size_t row = 0; row < result.size(); row++ ) {
		cout << "[";
		for ( size_t num = 0; num < result[row].size(); num++ ) {
			cout << result[row][num];
			if ( num + 1 != result[row].size() )
				cout << ",";
		}
		cout << "]" << endl;
	}
}