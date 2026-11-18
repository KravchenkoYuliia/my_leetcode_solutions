public class DeleteDuplicates {

    public static ListNode deleteDuplicates( ListNode head ) {

        if ( head == null )
            return head;

        ListNode    prev = head;
        ListNode    curr = head.next;

        while ( curr != null ) {
            if ( prev.val == curr.val )
                prev.next = curr.next;
            else
                prev = curr;
            curr = curr.next;
        }
        return head;
    }
}