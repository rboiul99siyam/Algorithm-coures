#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1; // left er size nilam
    int L[left_size + 1];        // erpor left er size ta copy kore arek ta array te raklam

    int right_size = r - mid; // right er size nilam
    int R[right_size + 1];    // erpor right er size ta copy kore arek ta array te raklam

    for (int i = l, j = 0; i <= mid; i++, j++) // er loop caliye nums[i] er value gula ke l[j] er maje raklam
        L[j] = nums[i];

    for (int i = mid + 1, j = 0; i <= r; i++, j++) // er loop caliye num[i] er value gula ke R[j] er maje raklam
        R[j] = nums[i];

    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
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
void mergeSort(int l, int r)
{

    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(0, n - 1);
    // sort(nums, nums + n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}