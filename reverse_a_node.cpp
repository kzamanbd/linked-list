#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void reverseList(ListNode *&head, ListNode *current)
{
    if (current->next == NULL)
    {
        head = current;
        return;
    }
    reverseList(head, current->next);
    current->next->next = current;
    current->next = NULL;
}

int main()
{
    ListNode *head = new ListNode(10);
    ListNode *a = new ListNode(10);
    ListNode *b = new ListNode(20);
    ListNode *c = new ListNode(30);
    ListNode *d = new ListNode(450);
    ListNode *e = new ListNode(560);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Initialize current, previous and next pointers
    ListNode *current = head;
    ListNode *prev = NULL, *next = NULL;

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