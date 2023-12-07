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
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;
    int count1 = 0;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head1, tail1, x);
        count1++;
    }

    // insert second list
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int count2 = 0;

    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head2, tail2, x);
        count2++;
    }

    if (count1 == count2)
    {
        Node *currentNode1 = head1;
        Node *currentNode2 = head2;
        int flag = 1;
        while (currentNode1 != NULL)
        {
            if (currentNode1->val != currentNode2->val)
            {
                flag = 0;
            }
            currentNode1 = currentNode1->next;
            currentNode2 = currentNode2->next;
        }
        if (flag == 1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}