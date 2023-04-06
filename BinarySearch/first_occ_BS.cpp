#include <bits/stdc++.h>
using namespace std;

int binary_search1(vector<int> v, int n)
{
    int high = v.size() - 1, low = 0;
    int mid = 0, res = -1;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (v[mid] == n)
        {
            res = mid;
            high = mid - 1;
        }
        else if (v[mid] > n)
        {
            high = mid - 1;
        }
        else if (v[mid] < n)
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> v = {10, 50, 50, 50, 60, 60};
    int n = 50;
    cout << binary_search1(v, n) << endl;
}
