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

void deleteAtTail(ListNode *head)
{
    ListNode *currentNode = head;
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }

    cout << currentNode->val << endl;

    ListNode *deletedNode = currentNode->next;
    // delete deletedNode;
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

    deleteAtTail(head);
    ListNode *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }

    return 0;
}