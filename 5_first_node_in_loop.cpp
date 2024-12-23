ListNode *detectCycle(ListNode *A)
{
    unordered_set<ListNode *> uset;
    ListNode *ptr = A;

    while (ptr != NULL)
    {
        if (uset.find(ptr) != uset.end())
            return ptr;
        else
            uset.insert(ptr);

        ptr = ptr->next;
    }
    return NULL;
}
