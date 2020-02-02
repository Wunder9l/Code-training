/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        if (head == null) {
            return null;
        }
        
        var current = head;
        for (i in 1 until n) {   // move to n-th from head
            current = current?.next;
        }
        
        var toDelete = head;
        var parent: ListNode? = null;
        while (current?.next != null) {
            current = current?.next;
            parent = toDelete;
            toDelete = toDelete?.next;
        }
        
        // remove n-th node (current points to the last element)
        if (toDelete == head) {
            return head?.next;
        } else {
            parent?.next = toDelete?.next;    
        }
        
        return head;
    }
}
