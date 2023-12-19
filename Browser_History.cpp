#include <bits/stdc++.h>
using namespace std;

int getIndex(list<string> history, string value)
{
    int index = 0;
    for (auto h : history)
    {
        if (h == value)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int main()
{

    list<string> history;
    string s;

    while (true)
    {
        cin >> s;
        if (s == "end")
        {
            break;
        }
        history.push_back(s);
    }

    int query, position;
    cin >> query;
    while (query--)
    {
        // exec query
        string action, value;
        cin >> action;
        if (action == "visit")
        {
            cin >> value;
            auto it = find(history.begin(), history.end(), value);
            if (it == history.end())
            {
                cout << "Not Available";
            }
            else
            {
                position = getIndex(history, *it);
                cout << *it;
            }
        }
        else if (action == "prev")
        {
            position--;
            cout << position << " - "
                 << "previous called";
        }
        else if (action == "next")
        {
            // go to next;
            cout << "next called";
        }
        cout << endl;
    }

    // for (string st : history)
    // {
    //     cout << st << endl;
    // }
    return 0;
}