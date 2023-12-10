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

    int flag = 1;
    while (currentNode != NULL)
    {
        if (currentNode->next != NULL && currentNode->val > currentNode->next->val)
        {
            flag = 0;
            break;
        }
        currentNode = currentNode->next;
    }

    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}