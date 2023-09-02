#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int nums[N];

void marge(int l, int mid, int r)
{
    int leftSize = mid - l + 1;
    int L[leftSize + 1];

    int rightSize =  r - mid;
    int R[rightSize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = nums[i];
    }

    L[leftSize] = INT_MIN;
    R[rightSize] = INT_MIN;
    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {

        if (L[lp] >= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}
void divide(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2; // mid ber korlam
    divide(l, mid);
    divide(mid + 1, r);
    marge(l, mid, r);
}
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    divide(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}