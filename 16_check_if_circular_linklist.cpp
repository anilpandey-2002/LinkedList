
bool isCircular(Node *head)
{
    if (head->next == NULL)
        return 0;

    Node *curr = head->next;

    while (curr->next && curr->next != head)
        curr = curr->next;

    return curr->next == head;
}