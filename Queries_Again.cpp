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

// count size
int size(ListNode *head)
{
    int count = 0;
    ListNode *node = head;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

// insert node
void insertAtAny(ListNode *&head, ListNode *&tail, int position, int val)
{
    ListNode *newNode = new ListNode(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    // insert at head if position == 0
    else if (position == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // insert at tail
    else if (position == size(head))
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        // insert at any position
        ListNode *node = head;
        for (int i = 1; i < position; i++)
        {
            node = node->next;
        }

        // connect the next and previous node
        newNode->next = node->next;
        node->next = newNode;

        newNode->next->prev = newNode;
        newNode->prev = node;
    }
}

// print left to right
void printLeftToRight(ListNode *head)
{
    cout << "L -> ";
    ListNode *node = head;
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// print right to left
void printRightToLeft(ListNode *tail)
{
    cout << "R -> ";
    ListNode *node = tail;
    while (node)
    {
        cout << node->val << " ";
        node = node->prev;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int position, value;
        cin >> position >> value;
        if (position > size(head))
        {
            cout << "Invalid" << endl;
            continue;
        }
        insertAtAny(head, tail, position, value);
        printLeftToRight(head);
        printRightToLeft(tail);
    }

    return 0;
}