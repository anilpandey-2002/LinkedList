#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(NULL) {}
};

struct LinkedList
{
    Node *head;
    LinkedList() : head(NULL) {}

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print()
    {
        for (Node *temp = head; temp; temp = temp->next)
            cout << temp->data << " ";
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

Node *reverse(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void reverseUtil(Node *curr, Node *prev, Node **head)
{
    if (!curr->next)
    {
        *head = curr;
        curr->next = prev;
        return;
    }
    Node *next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, head);
}

void reverse(Node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseLL(Node **head)
{
    stack<Node *> s;
    Node *temp = *head;
    while (temp->next)
    {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int count(Node *head)
{
    int k = 1;
    for (Node *p = head; p; p = p->next)
        k++;
    return k;
}

Node *ll_reverse(Node *head)
{
    Node *p = head;
    int i = count(head), j = 1;
    vector<int> arr(i);
    while (i && p)
    {
        arr[j++] = p->data;
        p = p->next;
        i--;
    }
    for (j--; j > 0; j--)
        cout << arr[j] << " ";
    return head;
}

int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
    ll.reverse();
    cout << "\nReversed Linked list\n";
    ll.print();
    return 0;
}
