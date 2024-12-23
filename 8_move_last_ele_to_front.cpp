void moveToFront(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *last = head, *second_last = NULL;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = head;
    head = last;
}
