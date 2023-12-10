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

void printList(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
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

    vector<int> v;
    Node *currentNode = head;
    Node *previousNode = NULL;

    while (currentNode != NULL)
    {
        if (find(v.begin(), v.end(), currentNode->val) == v.end())
        {
            v.push_back(currentNode->val);
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        else
        {
            Node *deletedNode = currentNode;
            previousNode->next = currentNode->next;
            currentNode = currentNode->next;
            delete deletedNode;
        }
    }

    printList(head);
    return 0;
}