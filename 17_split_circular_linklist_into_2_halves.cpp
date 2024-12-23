void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    int size = 1;

    Node *last = head;
    while (last->next != head)
    {
        size++;
        last = last->next;
    }

    if (size % 2 == 0)
        size--;
    size = size / 2;

    Node *middle = head;
    for (int i = 0; i < size; i++)
    {
        middle = middle->next;
    }

    *head1_ref = head;
    *head2_ref = middle->next;

    middle->next = *head1_ref;
    last->next = *head2_ref;
}
