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

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
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

int main()
{
    Node *head = NULL;

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
    Node *currentNode = head;

    int count = 0;

    while (currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }
    int mid = count / 2;
    currentNode = head;

    for (int i = 0; i < mid - 1; i++)
    {
        currentNode = currentNode->next;
    }

    if (count % 2 == 0)
    {
        cout << currentNode->val << " " << currentNode->next->val;
    }
    else
    {
        cout << currentNode->next->val;
    }

    return 0;
}