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

void insert_at_tail(Node *&head, int n)
{

    Node *newNode = new Node(n);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *currentNode = head;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void deleted_at_any(Node *&head, int position)
{
    Node *currentNode = head;
    if (position - 1 == 0)
    {
        // Node *deletedNode = currentNode;
        head = head->next;
        // delete currentNode;
    }
    else
    {
        for (int i = 1; i < position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        Node *deletedNode = currentNode->next;
        // currentNode->next = currentNode->next->next;
        currentNode->next = deletedNode->next;
        delete deletedNode;
    }
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;
    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_tail(head, 40);

    deleted_at_any(head, n);

    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}