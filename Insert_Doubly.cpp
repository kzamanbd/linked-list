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
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

void insertAtAny(ListNode *&head, int value, int position = -1)
{
    ListNode *newNode = new ListNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else if (position == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    ListNode *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    newNode->next->prev = currentNode;
    currentNode->prev = newNode;
}

void insertAtTail(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    newNode->prev = currentNode;
    currentNode->next = newNode;
}

int main()
{

    ListNode *head = NULL, tail = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, x);
    }

    printList(head);

    return 0;
}