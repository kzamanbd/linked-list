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

    ListNode *current = head;

    while (current != NULL)
    {
        cout << current->val << endl;
        current = current->next;
    }
    return 0;
}