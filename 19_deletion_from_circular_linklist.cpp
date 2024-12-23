void deleteNode(Node *head, int key)
{
    if (head == NULL)
        return;

    if (head->next == head && head->data == key)
    {
        free(head);
        head = NULL;
        return;
    }

    Node *last = head;

    if (head->data == key)
    {
        while (last->next != head)
            last = last->next;
        last->next = head->next;
        free(head);
        head = last->next;
        return;
    }

    while (last->next != head && last->next->data != key)
    {
        last = last->next;
    }

    if (last->next->data == key)
    {
        Node *d = last->next;
        last->next = last->next->next;
        free(d);
        return;
    }
}
