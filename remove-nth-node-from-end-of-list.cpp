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

Node *removeNthFromEnd(Node *head, int n)
{
    Node *currentNode = head;
    for (int i = 0; i < n; i++)
    {
        currentNode = currentNode->next;
    }
    Node *deletedNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete deletedNode;
    return head;
}

int main()
{
    int x, n;
    cin >> n;
    Node *head = NULL;
    while (cin >> x)
    {
        insertAtTail(head, x);
    }

    Node *currentNode = removeNthFromEnd(head, n);

    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    return 0;
}

