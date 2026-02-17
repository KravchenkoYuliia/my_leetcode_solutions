import sys

class Solution:
    def mySqrt(self, x: int) -> int:

        if x == 0:
            return 0
        if x < 4:
            return 1
        i = 1

        while i < x:
            result = i * i
            if result == x:
                return i
            elif result > x:
                return i - 1
            i += 1
             

        return 0

def main():

    if len( sys.argv ) > 1:
    
        s = Solution()
        print( s.mySqrt( int(sys.argv[1]) ) )

if __name__=="__main__":
    main()