ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next)
    {
        slow = slow->next;

        if (fast->next->next == NULL)
            break;

        fast = fast->next->next;
    }
    return slow;
}
