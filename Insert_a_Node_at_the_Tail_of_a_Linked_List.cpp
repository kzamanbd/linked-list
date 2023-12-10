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

void insertAtTail(ListNode *&head, ListNode *&tail, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int x;
        cin >> x;
        insertAtTail(head, tail, x);
    }

    ListNode *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}