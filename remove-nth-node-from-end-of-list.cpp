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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *currentNode = head;
    for (int i = 0; i < n; i++)
    {
        currentNode = currentNode->next;
    }
    ListNode *deletedNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete deletedNode;
    return head;
}

int main()
{
    int x, n;
    cin >> n;
    ListNode *head = NULL;
    while (cin >> x)
    {
        insertAtTail(head, x);
    }

    ListNode *currentNode = removeNthFromEnd(head, n);

    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    return 0;
}

