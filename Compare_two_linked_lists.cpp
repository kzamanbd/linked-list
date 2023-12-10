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

void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, tail, x);
    }
    Node *currentNode = head;

    int max = INT_MIN;
    int min = INT_MAX;

    while (currentNode != NULL)
    {
        if (max < currentNode->val)
        {
            max = currentNode->val;
        }
        if (min > currentNode->val)
        {
            min = currentNode->val;
        }
        currentNode = currentNode->next;
    }

    cout << max - min;

    return 0;
}