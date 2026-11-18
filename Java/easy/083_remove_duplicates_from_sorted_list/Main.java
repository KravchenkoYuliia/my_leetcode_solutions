public class Main {

    public static void main( String[] args ) {
        
        ListNode    head = new ListNode( 1 );
        head.next = new ListNode( 1 );
        head.next.next = new ListNode( 3 );
        head.next.next.next = new ListNode( 3 );
        head.next.next.next.next = new ListNode( 5 );
        head.next.next.next.next.next = new ListNode( 5 );
        head.next.next.next.next.next.next = new ListNode( 9 );

        ListNode    listWithoutDoubles = DeleteDuplicates.deleteDuplicates( head );
        PrintList.print( head );

    }
    
}

class PrintList {

    public static void print( ListNode list ) {

        while ( list != null ) {

            System.out.print( list.val + "->" );
            list = list.next;

        }
        System.out.println( "null" );

    }

}