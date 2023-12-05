#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_any(Node *&head, int n, int position = 0)
{

    Node *newNode = new Node(n);

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
            Node *currentNode = head;
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
        Node *currentNode = head;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_any(head, 40);
    insert_at_any(head, 50);
    insert_at_any(head, 8000, 1000000);

    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}