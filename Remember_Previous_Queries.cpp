#include <bits/stdc++.h>
using namespace std;

void printLeftToRight(list<int> queries)
{
    cout << "L -> ";
    if (queries.empty())
    {
        cout << endl;
        return;
    }
    for (int v : queries)
    {
        cout << v << " ";
    }
    cout << endl;
}

void printRightToLeft(list<int> queries)
{
    cout << "R -> ";
    if (queries.empty())
    {
        cout << endl;
        return;
    }
    list<int> copyQueries(queries);
    copyQueries.reverse();
    for (int v : copyQueries)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{

    list<int> queries;
    int n;
    cin >> n;
    while (n--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            queries.push_front(v);
        }
        else if (x == 1)
        {
            queries.push_back(v);
        }
        else
        {
            int size = queries.size();
            if (v < size)
            {
                queries.erase(next(queries.begin(), v));
            }
        }
        printLeftToRight(queries);
        printRightToLeft(queries);
    }
    return 0;
}