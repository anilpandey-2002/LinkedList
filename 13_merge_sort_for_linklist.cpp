// Using Merge Sort
Node *SortedMerge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data <= b->data)
    {
        a->next = SortedMerge(a->next, b);
        return a;
    }
    else
    {
        b->next = SortedMerge(a, b->next);
        return b;
    }
}

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast = source, *slow = source;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(Node **headRef)
{
    Node *head = *headRef;
    if (!head || !head->next)
        return;
    Node *a, *b;
    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a, b);
}
