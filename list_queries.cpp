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

void displayList(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
}

void insertAnyPosition(Node *&head, int position, int val)
{
    Node *newNode = new Node(val);

    Node *currentNode = head;

    for (int i = 0; i < position - 1; i++)
    {
        if (currentNode->next == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
        currentNode = currentNode->next;
    }

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    displayList(head);
    cout << endl;
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

    int q;
    cin >> q;
    while (q--)
    {
        int position, value;
        cin >> position >> value;
        insertAnyPosition(head, position, value);
    }

    return 0;
}