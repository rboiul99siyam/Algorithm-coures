// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int ar[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ar[i];
//     }

//     int i = 0, j = n - 1;
//     while (i < j)
//     {
//         int tmp = ar[i];
//         ar[i] = ar[j];
//         ar[j] = tmp;
//         i++;
//         j--;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << ar[i] << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                int tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}