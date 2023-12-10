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

int countSize(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtAny(ListNode *&head, int action, int v)
{
    ListNode *newNode = new ListNode(v);

    // insert at head
    if (head == NULL)
    {
        head = newNode;
    }
    else if (action == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    // insert at tail
    else if (action == 1)
    {
        ListNode *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void deleteNode(ListNode *&head, int position)
{
    if (position > countSize(head))
    {
        return;
    }
    if (position == 0 && head != NULL)
    {
        head = head->next;
        return;
    }
    ListNode *currentNode = head;
    for (int i = 1; i < position; i++)
    {
        currentNode = currentNode->next;
    }
    if (currentNode != NULL && currentNode->next != NULL)
    {
        ListNode *deletedNode = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete deletedNode;
    }
}

int main()
{
    ListNode *head = NULL;

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int action, v;
        cin >> action >> v;
        if (action == 2)
        {
            deleteNode(head, v);
        }
        else
        {
            insertAtAny(head, action, v);
        }
        printList(head);
    }

    return 0;
}