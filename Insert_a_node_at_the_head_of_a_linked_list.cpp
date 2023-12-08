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

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

int main()
{
    Node *head = NULL;

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int x;
        cin >> x;
        insertAtHead(head, x);
    }

    Node *currentNode = head;

    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }

    return 0;
}