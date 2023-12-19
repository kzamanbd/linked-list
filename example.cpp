#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int size)
{
    int i, j, item;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        item = A[i];
        while (j >= 0 && A[j] > item)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = item;
    }
}

int main()
{

    return 0;
}