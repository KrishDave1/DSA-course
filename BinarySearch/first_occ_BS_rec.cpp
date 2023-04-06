#include <bits/stdc++.h>
using namespace std;

int binary_search1(vector<int> v, int n, int high, int low)
{
    int mid = 0;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (v[mid] == n)
        {
            if (binary_search1(v, n, mid - 1, 0) == -1)
                return mid;
            else
                return binary_search1(v, n, mid - 1, 0);
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
    return -1;
}

int main()
{
    vector<int> v = {10, 50, 50, 50, 60, 60};
    int n = 50, b = v.size() - 1;
    cout << binary_search1(v, n, b, 0) << endl;
}
