#include <bits/stdc++.h>
using namespace std;

int reverse_BS(vector<int> a, int ele)
{
    int low = 0;
    int high = a.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == ele)
        {
            return mid;
        }
        else if (a[mid] < ele)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (a[low]==ele)
    return low;
    return -1;
}

int main()
{
    vector<int> a = {80, 60, 50, 40, 20, 10};
    cout << reverse_BS(a, 70) << endl;
    return 0;
}