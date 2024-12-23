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

Node *addOne(Node *head)
{
    head = reverse(head);
    Node *curr = head, *prev = NULL;
    int carry = 1;
    while (curr)
    {
        int newData = curr->data + carry;
        if (newData < 10)
        {
            curr->data = newData;
            carry = 0;
            break;
        }
        else
        {
            curr->data = newData % 10;
            carry = newData / 10;
        }
        prev = curr;
        curr = curr->next;
    }
    if (carry)
    {
        while (carry)
        {
            Node *newNode = new Node(carry % 10);
            prev->next = newNode;
            prev = newNode;
            carry /= 10;
        }
    }
    head = reverse(head);
    return head;
}

int addWithCarry(Node *head)
{
    if (!head)
        return 1;
    int res = head->data + addWithCarry(head->next);
    head->data = res % 10;
    return res / 10;
}
