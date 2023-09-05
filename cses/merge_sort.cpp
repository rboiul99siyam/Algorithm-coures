#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];
void merge(int l, int mid, int r)
{
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int L[left_size + 1];
    int R[right_size + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i]; // nums array er value l er modde diye dilam ba stor  raklam
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = nums[i];

    int lp = 0, rp = 0;
    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;

    for (int i = l; i <= r; i++)
    {
        if (L[lp] < R[rp])
        {
            nums[i] = L[lp];
        }
        else
        {
            nums[i] = R[rp];
        }
    }
}

void mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergesort(l, mid);     // left e gelo
    mergesort(mid + 1, r); // right e gelo
    merge(l, mid, r);      // merge korbo
}
int main()
{
    int n;
    cin >> n; // ekta n input nilam
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // ar input nilam
    }

    mergesort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}