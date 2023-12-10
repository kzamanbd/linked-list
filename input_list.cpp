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
    int x;
    ListNode *head = NULL;
    while (cin >> x)
    {
        insertAtTail(head, x);
    }

    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }

    return 0;
}