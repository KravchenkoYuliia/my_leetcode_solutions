import java.util.Arrays;

public class Main {

    public static void main( String[] args ) {

        int[] nums1 = new int[6];
        nums1[0] = 1;
        nums1[1] = 2;
        nums1[2] = 3;

        int[] nums2 = new int[]{ 20, 30, 40 };

        MergeSortedArray m = new MergeSortedArray();
        m.merge( nums1, 3, nums2, 3 );

        System.out.println( "The result of merge is " + Arrays.toString( nums1 ) );

    }

}