#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    string val;
    ListNode *next;
    ListNode *prev;

    ListNode(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(ListNode *&head, ListNode *&tail, string val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

ListNode *findElement(ListNode *head, string value)
{
    ListNode *currentNode = head;
    while (currentNode)
    {
        if (currentNode->val == value)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    string x;

    while (true)
    {
        cin >> x;
        if (x == "end")
        {
            break;
        }
        insertAtTail(head, tail, x);
    }

    int query;
    cin >> query;
    ListNode *currentNode = NULL;
    while (query--)
    {
        // exec query
        string action;
        cin >> action;

        if (action == "visit")
        {
            string value;
            cin >> value;
            ListNode *findEl = findElement(head, value);
            if (findEl == NULL)
            {
                cout << "Not Available";
            }
            else
            {
                currentNode = findEl;
                cout << currentNode->val;
            }
        }
        else if (action == "prev")
        {
            if (currentNode->prev)
            {
                currentNode = currentNode->prev;
                cout << currentNode->val;
            }
            else
            {
                cout << "Not Available";
            }
        }
        else if (action == "next")
        {
            if (currentNode->next)
            {
                currentNode = currentNode->next;
                cout << currentNode->val;
            }
            else
            {
                cout << "Not Available";
            }
        }
        cout << endl;
    }

    return 0;
}