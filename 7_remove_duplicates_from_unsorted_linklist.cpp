Node *removeDuplicates(Node *head)
{
    unordered_set<int> s;
    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        while (curr && s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            prev->next = NULL;
            return head;
        }

        s.insert(curr->data);
        prev = curr;
        curr = curr->next;
    }
    return head;
}
