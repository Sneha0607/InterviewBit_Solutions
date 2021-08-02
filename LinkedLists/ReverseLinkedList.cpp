/* Reverse Linked List
*/

ListNode* Solution::reverseList(ListNode* A) {
    ListNode* next;
    ListNode* prev;
    ListNode* curr;
    curr = A;
    prev = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
