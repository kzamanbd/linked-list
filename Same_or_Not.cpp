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

    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;
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
    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;
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
        ListNode *currentNode1 = head1;
        ListNode *currentNode2 = head2;
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