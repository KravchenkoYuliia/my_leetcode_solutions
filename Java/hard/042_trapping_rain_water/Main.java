public class Main {

    public static void  main( String[] args ) {

        int[]   height = new int[]{ 0,1,0,2,1,0,1,3,2,1,2,1 };

        int result = CalculateTrapedWater.trap( height );
        System.out.println( "Traped " + result + " units of water" );

    }

}