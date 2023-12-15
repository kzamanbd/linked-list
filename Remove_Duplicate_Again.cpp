#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
        {
            break;
        }
        l.push_back(x);
    }
    l.sort();
    l.unique();
    for (int v : l)
    {
        cout << v << " ";
    }

    return 0;
}