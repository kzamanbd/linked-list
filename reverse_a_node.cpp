#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(450);
    Node *e = new Node(560);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Initialize current, previous and next pointers
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    head = prev;

    current = head;

    while (current != NULL)
    {
        cout << current->val << endl;
        current = current->next;
    }
    return 0;
}