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

void insert_at_tail(ListNode *&head, int n)
{

    ListNode *newNode = new ListNode(n);

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

    insert_at_tail(head, 52);

    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}