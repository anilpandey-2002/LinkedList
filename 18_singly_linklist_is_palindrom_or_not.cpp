
bool isPalindrome(Node *head)
{
    string s = "", s_dup = "";

    while (head)
    {
        s += ('0' + head->data);
        head = head->next;
    }
    s_dup = s;
    reverse(s_dup.begin(), s_dup.end());
    return s_dup == s;
}
