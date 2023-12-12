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

void printReverseList(ListNode *tail)
{
    ListNode *node = tail;
    while (node)
    {
        cout << node->val << " ";
        node = node->prev;
    }
    cout << endl;
}

int size(ListNode *head)
{
    ListNode *node = head;
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

void insertAtAny(ListNode *&head, ListNode *&tail, int val, int position = -1)
{
    ListNode *newNode = new ListNode(val);

    if (position == 0)
    {
        // insert at head
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    else if (position >= size(head))
    {
        // invalid position
        cout << "Invalid Position" << endl;
    }
    else if (position > 0 && position < size(head))
    {
        // insert at any position
        ListNode *node = head;
        for (int i = 1; i < position; i++)
        {
            node = node->next;
        }
        // insert node at this position
        newNode->next = node->next;
        node->next = newNode;

        // update previous
        newNode->next->prev = newNode;
        newNode->prev = node;
    }
    else
    {
        // insert at tail
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

int main()
{

    // ListNode *head = new ListNode(10);
    // ListNode *a = new ListNode(20);
    // ListNode *tail = new ListNode(30);

    // head->next = a;
    // a->prev = head;
    // a->next = tail;
    // tail->prev = a;

    ListNode *head = NULL, *tail = NULL;

    insertAtAny(head, tail, 20);
    insertAtAny(head, tail, 30);
    insertAtAny(head, tail, 40);
    insertAtAny(head, tail, 10, 1);
    insertAtAny(head, tail, 50, 0);

    printList(head);
    printReverseList(tail);

    return 0;
}