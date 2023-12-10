#include <bits/stdc++.h>
using namespace std;

vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
{
    vector<int> v;
    for (int i = 0; i < variables.size(); i++)
    {
        int firstPow = pow(variables[i][0], variables[i][1]);
        int firstMod = firstPow % 10;
        int secondPow = pow(firstMod, variables[i][2]);
        cout<<secondPow;

        if ((secondPow % variables[i][3]) == target)
        {
            v.push_back(i);
        }
    }
    return v;
}

int main()
{

    int n;
    cin >> n;
    // vector<vector<int>> variables = {{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}};
    vector<vector<int>> variables = {{39, 3, 1000, 1000}};
    vector<int> result = getGoodIndices(variables, 2);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}