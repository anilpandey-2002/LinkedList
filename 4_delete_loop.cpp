void removeLoop(Node *head)
{
    unordered_set<Node *> s;
    Node *curr = head;
    s.insert(curr);

    while (curr->next != NULL)
    {
        if (s.find(curr->next) != s.end())
        {
            curr->next = NULL;
            return;
        }
        s.insert(curr->next);
        curr = curr->next;
    }
}
