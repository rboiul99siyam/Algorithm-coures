#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int ar[x];
        for (int i = 0; i < x; i++)
        {
            cin >> ar[i];
        }
        sort(ar, ar + x);
        for (int i = 0; i < n - 1; i++)
        {
            if (ar[i] == ar[i + 1])
            {
                ar[i]==ar[i+1];
            }
        }
        for(int i=0;i<x;i++)
        {
            cout<<ar[i]<<" ";
        }
    }
    return 0;
}