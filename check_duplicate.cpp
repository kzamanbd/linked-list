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

    int count[100] = {0};

    while (currentNode != NULL)
    {
        count[currentNode->val]++;
        currentNode = currentNode->next;
    }
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (count[i] > 1)
        {
            flag = 1;
            break;
        }
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