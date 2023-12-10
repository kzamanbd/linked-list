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

    int testCase;
    cin >> testCase;
    while (testCase--)
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

        int x;
        cin >> x;
        int index = 0;
        int flag = 0;

        Node *currentNode = head;

        while (currentNode != NULL)
        {
            if (currentNode->val == x)
            {
                flag = 1;
                break;
            }
            else if (x > 1000000)
            {
                break;
            }
            index++;
            currentNode = currentNode->next;
        }
        if (flag == 1)
        {
            cout << index;
        }
        else
        {
            cout << "-1";
        }
        cout << endl;
    }

    return 0;
}