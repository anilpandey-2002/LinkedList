struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    for (Node *i = head->next; i != NULL; i = i->next)
    {
        Node *j = i;
        while (j->prev != NULL && j->data < j->prev->data)
        {
            Node *temp = j->prev->prev;
            Node *temp2 = j->prev;
            Node *temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if (temp != NULL)
                temp->next = j;
            if (temp3 != NULL)
                temp3->prev = temp2;
        }

        if (j->prev == NULL)
            head = j;
    }
    return head;
}

struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL)
        return head;

    priority_queue<Node *, vector<Node *>, compare> pq;

    struct Node *newHead = NULL, *last;

    for (int i = 0; head != NULL && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return newHead;
}
