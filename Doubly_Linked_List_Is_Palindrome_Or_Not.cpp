#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// insert node
void insertAtTail(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // insert at tail
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
// check palindrome
bool isPalindrome(ListNode *head, ListNode *tail)
{
    ListNode *i = head, *j = tail;
    while (i != j)
    {
        if (i->val != j->val)
        {
            return false;
        }
        i = i->next;
        j = j->prev;
    }

    return true;
}

int main()
{
    ListNode *head = NULL, *tail = NULL;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        insertAtTail(head, tail, x);
    }

    // check if is palindrome
    if (isPalindrome(head, tail))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}