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

int countSize(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtAny(Node *&head, int action, int v)
{
    Node *newNode = new Node(v);

    // insert at head
    if (head == NULL)
    {
        head = newNode;
    }
    else if (action == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    // insert at tail
    else if (action == 1)
    {
        Node *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void deleteNode(Node *&head, int position)
{
    if (position > countSize(head))
    {
        return;
    }
    if (position == 0 && head != NULL)
    {
        head = head->next;
        return;
    }
    Node *currentNode = head;
    for (int i = 1; i < position; i++)
    {
        currentNode = currentNode->next;
    }
    if (currentNode != NULL && currentNode->next != NULL)
    {
        Node *deletedNode = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete deletedNode;
    }
}

int main()
{
    Node *head = NULL;

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int action, v;
        cin >> action >> v;
        if (action == 2)
        {
            deleteNode(head, v);
        }
        else
        {
            insertAtAny(head, action, v);
        }
        printList(head);
    }

    return 0;
}