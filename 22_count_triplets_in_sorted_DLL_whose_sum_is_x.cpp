int countTriplets(struct Node *head, int x)
{
    struct Node *ptr1, *ptr2, *ptr3;
    int count = 0;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
                    count++;

    return count;
}

int countTriplets(struct Node *head, int x)
{
    struct Node *ptr, *ptr1, *ptr2;
    int count = 0;

    unordered_map<int, Node *> um;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            int p_sum = ptr1->data + ptr2->data;

            if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1 && um[x - p_sum] != ptr2)
                count++;
        }

    return (count / 3);
}

int countPairs(struct Node *first, struct Node *second, int value)
{
    int count = 0;

    while (first != NULL && second != NULL &&
           first != second && second->next != first)
    {
        if ((first->data + second->data) == value)
        {
            count++;
            first = first->next;
            second = second->prev;
        }
        else if ((first->data + second->data) > value)
            second = second->prev;
        else
            first = first->next;
    }

    return count;
}

int countTriplets(struct Node *head, int x)
{
    if (head == NULL)
        return 0;

    struct Node *current, *first, *last;
    int count = 0;

    last = head;
    while (last->next != NULL)
        last = last->next;

    for (current = head; current != NULL; current = current->next)
    {
        first = current->next;
        count += countPairs(first, last, x - current->data);
    }

    return count;
}
