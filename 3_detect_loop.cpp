#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(NULL) {}
};

bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next; // Creating a loop for testing

    if (detectLoop(head))
        cout << "Loop detected\n";
    else
        cout << "No loop\n";

    return 0;
}
