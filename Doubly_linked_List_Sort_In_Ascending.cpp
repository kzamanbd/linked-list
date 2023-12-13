#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// insert node
void insertAtTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // insert at tail
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// sort by asc order
void sortAsAsc(ListNode *head)
{
    for (ListNode *i = head; i->next != NULL; i = i->next)
    {
        for (ListNode *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

void printList(ListNode *head)
{
    ListNode *node = head;
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, tail, x);
    }

    // sort list
    sortAsAsc(head);
    // print list
    printList(head);
    return 0;
}