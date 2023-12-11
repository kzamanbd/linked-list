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

// selection sort
void sortedList(ListNode *head)
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

void deleteLinkedList(ListNode *head, int value)
{
    ListNode *currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->next != NULL && currentNode->next->val == value)
        {
            cout << "It will be deleted " << currentNode->next->val << endl;
            // ListNode *deletedNode = currentNode->next;
            // currentNode = deletedNode->next;
            // delete deletedNode;
            currentNode = currentNode->next;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
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

    while (currentNode != NULL)
    {
        deleteLinkedList(head, currentNode->val);
        currentNode = currentNode->next;
    }

    printList(head);
    return 0;
}