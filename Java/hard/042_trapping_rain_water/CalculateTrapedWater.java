import java.util.Arrays;

public class CalculateTrapedWater {

	public static int trap ( int[] height ) {
		
		int result = 0;
		int	l = 0;
		int	r = height.length - 1;

		int	leftMaxValue = height[l];
		int	rightMaxValue = height[r];

		while ( l < r ) {
			if ( height[l] > leftMaxValue )
				leftMaxValue =  height[l];
			if ( height[r] > rightMaxValue )
				rightMaxValue = height[r];

			if ( height[l] <= height[r] ) {
				result += Math.min( leftMaxValue, rightMaxValue ) - height[l];
				l++;
			}
			else {
				result += Math.min( leftMaxValue, rightMaxValue ) - height[r];
				r--;
			}
		}

		return result;
	}

}