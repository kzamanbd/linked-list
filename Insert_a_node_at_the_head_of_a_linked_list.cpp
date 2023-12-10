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

void insertAtHead(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);

    newNode->next = head;
    head = newNode;
}

int main()
{
    ListNode *head = NULL;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int x;
        cin >> x;
        insertAtHead(head, x);
    }

    ListNode *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}