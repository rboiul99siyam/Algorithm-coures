// // ei program er time compilxity 2^n khbu baje ;

// #include <bits/stdc++.h>
// using namespace std;

// int fibo(int n)
// {
//     // base case

//     if (n == 0 || n == 1)
//         return 1;

//     // recarsion
//     int ans1 = fibo(n - 1);
//     int ans2 = fibo(n - 2);
//     return ans1 + ans2;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << fibo(n) << endl;

//     return 0;
// }

// /* sample input ;
// 4
// output : 5 */

#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int ans1 = fibo(n - 1);
    int ans2 = fibo(n - 2);
    return ans1 + ans2;
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}