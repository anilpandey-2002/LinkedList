Node *reverse(Node *head)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addTwoLists(Node *first, Node *second)
{
    Node *head = NULL, *prev = NULL, *temp = NULL;
    first = reverse(first);
    second = reverse(second);
    int carry = 0;

    while (first || second)
    {
        int curr_sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
        carry = curr_sum / 10;
        curr_sum %= 10;
        temp = new Node(curr_sum);
        if (!head)
            head = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry)
        prev->next = new Node(carry);
    return reverse(head);
}

node *addSameSize(Node *head1, Node *head2, int *carry)
{
    if (!head1)
        return NULL;
    int sum;
    Node *result = new Node;
    result->next = addSameSize(head1->next, head2->next, carry);
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    result->data = sum % 10;
    return result;
}

void addCarryToRemaining(Node *head1, Node *cur, int *carry, Node **result)
{
    int sum;
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
        sum = head1->data + *carry;
        *carry = sum / 10;
        result = sum % 10;
        push(result, sum);
    }
}

void addList(Node *head1, Node *head2, Node **result)
{
    Node *cur;
    if (!head1)
    {
        *result = head2;
        return;
    }
    if (!head2)
    {
        *result = head1;
        return;
    }
    int size1 = getSize(head1), size2 = getSize(head2), carry = 0;
    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
    else
    {
        int diff = abs(size1 - size2);
        if (size1 < size2)
            swapPointer(&head1, &head2);
        for (cur = head1; diff--; cur = cur->next)
            ;
        *result = addSameSize(cur, head2, &carry);
        addCarryToRemaining(head1, cur, &carry, result);
    }
    if (carry)
        push(result, carry);
}
