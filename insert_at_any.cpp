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

void insert_at_any(ListNode *&head, int n, int position = 0)
{

    ListNode *newNode = new ListNode(n);

    if (position > 0)
    {
        // insert at head
        if (position - 1 == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            // insert at N position
            ListNode *currentNode = head;
            for (int i = 1; i < position - 1 && currentNode->next != NULL; i++)
            {
                currentNode = currentNode->next;
            }

            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
    else
    {
        // insert at tail
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

    ListNode *head = new ListNode(10);
    ListNode *a = new ListNode(20);
    ListNode *b = new ListNode(30);

    head->next = a;
    a->next = b;

    insert_at_any(head, 40);
    insert_at_any(head, 50);
    insert_at_any(head, 8000, 1000000);

    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}