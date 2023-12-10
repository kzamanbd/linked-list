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

void insertAtTail(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int main()
{
    ListNode *head = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, x);
    }
    ListNode *currentNode = head;

    int count = 0;

    while (currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }
    int mid = count / 2;
    currentNode = head;

    for (int i = 0; i < mid - 1; i++)
    {
        currentNode = currentNode->next;
    }

    if (count % 2 == 0)
    {
        cout << currentNode->val << " " << currentNode->next->val;
    }
    else
    {
        cout << currentNode->next->val;
    }

    return 0;
}