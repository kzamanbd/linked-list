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

    ListNode *head1 = NULL, *tail1 = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtAny(head1, tail1, x);
    }

    ListNode *head2 = NULL, *tail2 = NULL;

    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtAny(head2, tail2, x);
    }

    int count1 = size(head1);
    int count2 = size(head2);
    int flag = 1;
    if (count1 == count2)
    {
        ListNode *node1 = head1;
        ListNode *node2 = head2;

        while (node1)
        {
            if (node1->val != node2->val)
            {
                flag = 0;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    else
    {
        flag = 0;
    }
    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    // printList(head1);
    // printReverseList(tail1);
    return 0;
}