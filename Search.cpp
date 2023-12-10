#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode *&head, ListNode *&tail, int value)
{
    ListNode *newNode = new ListNode(value);
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
        ListNode *head = NULL;
        ListNode *tail = NULL;

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

        ListNode *currentNode = head;

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