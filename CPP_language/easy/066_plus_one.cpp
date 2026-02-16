#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int>     plusOne(vector<int>& digits) {

        int size = digits.size();

        if ( digits[ size - 1 ] < 9 ) {
            
            digits[ size -1 ] += 1;
            return digits;
        }
        else {

            digits[ size -1 ] = 0;
            int i = size - 2;
            while ( i >= 0  && digits[ i ] == 9 ) {
                digits[ i ] = 0;
                i--;
            }
            if ( i >= 0 )
                digits[ i ] += 1;
            else
                digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main( int ac, char** av ) {

    if ( ac != 2 ) {
        cerr << "./a.out \"1,2,3,4\"" << endl;
        return 1;
    }

    vector< int >   digits;

    for ( int i = 0; av[1][i]; i++ ) {
        if ( av[1][i] != ',' )
            digits.push_back( av[1][i] - '0' );
    }

    vector< int >   result = Solution().plusOne( digits );
    cout << "result: " << endl;
    for ( int i = 0; i < result.size(); i++ )
        cout << result[i];

    cout << endl;

    return 0;
}