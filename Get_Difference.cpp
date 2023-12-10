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
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, tail, x);
    }
    ListNode *currentNode = head;

    int max = INT_MIN;
    int min = INT_MAX;

    while (currentNode != NULL)
    {
        if (max < currentNode->val)
        {
            max = currentNode->val;
        }
        if (min > currentNode->val)
        {
            min = currentNode->val;
        }
        currentNode = currentNode->next;
    }

    cout << max - min;

    return 0;
}