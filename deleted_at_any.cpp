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

void deleted_at_any(ListNode *&head, int position)
{
    ListNode *currentNode = head;
    if (position - 1 == 0)
    {
        // ListNode *deletedNode = currentNode;
        head = head->next;
        // delete currentNode;
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        ListNode *deletedNode = currentNode->next;
        // currentNode->next = currentNode->next->next;
        currentNode->next = deletedNode->next;
        delete deletedNode;
    }
}

int main()
{
    int n;
    cin >> n;

    ListNode *head = NULL;
    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_tail(head, 40);

    deleted_at_any(head, n);

    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}