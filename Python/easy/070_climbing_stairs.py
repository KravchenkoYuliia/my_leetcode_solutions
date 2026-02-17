import sys

class Solution:
    def climbStairs(self, n: int) -> int:

        if n <= 3:
            return n
        
        prev = 2
        current = 3

        for _ in range(4, n+1):            
            prev, current = current, current + prev
        
        return current




def main():
        
        if len( sys.argv ) > 1:
            args = sys.argv[1]
            s = Solution()
            print( s.climbStairs( int(args) ))
        else:
             print("Give a number of stairs")

    

if __name__=="__main__":
    main()