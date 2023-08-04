#include <bits/stdc++.h>
using namespace std;

int binary_search2(vector<int> v, int n)
{
    int high = v.size() - 1, low = 0;
    int mid = 0, res = 0;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (v[mid] == n)
        {
            res = mid;
            low = mid + 1;
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

int binary_search1(vector<int> v, int n)
{
    int high = v.size() - 1, low = 0;
    int mid = 0, res = 0;
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
    vector<int> v = {10, 50, 50, 50, 50, 60};
    int n = 50;
    int first = binary_search1(v, n), last = binary_search2(v, n);
    cout << last - first + 1 << endl;
}
