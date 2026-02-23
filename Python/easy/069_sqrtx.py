import sys

class Solution:
    def mySqrt(self, x: int) -> int:

        start = 0
        end = x

        while end >= start :
            middle = start + ( end-start )//2

            if middle * middle > x:
                end = middle - 1
            elif middle * middle < x:
                start = middle + 1
            else:
                break

        if middle * middle > x:
            return middle - 1
        else:
            return middle

def main():

    if len( sys.argv ) > 1:
    
        s = Solution()
        print( s.mySqrt( int(sys.argv[1]) ) )

if __name__=="__main__":
    main()
