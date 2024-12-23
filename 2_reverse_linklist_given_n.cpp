#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(NULL) {}
};

Node *reverseGroup(Node *head, int k)
{
    if (!head)
        return NULL;
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverseGroup(next, k);
    return prev;
}

Node *reverseGroupStack(Node *head, int k)
{
    stack<Node *> s;
    Node *curr = head;
    Node *prev = NULL;
    while (curr)
    {
        int count = 0;
        while (curr && count < k)
        {
            s.push(curr);
            curr = curr->next;
            count++;
        }
        while (!s.empty())
        {
            if (!prev)
            {
                prev = s.top();
                head = prev;
                s.pop();
            }
            else
            {
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }
    if (prev)
        prev->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    for (Node *temp = head; temp; temp = temp->next)
        cout << temp->data << " ";

    head = reverseGroup(head, 2);
    cout << "\nReversed in Groups of 2: ";
    for (Node *temp = head; temp; temp = temp->next)
        cout << temp->data << " ";

    return 0;
}
