#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot_index(vector<int> a)
{
    // base case
    if (a.size() == 0)
        return -1;
    int low = 0, high = a.size() - 1, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // checking if mid is the pivot element
        if (a[mid] < a[(mid + 1) % a.size()] && a[mid] < a[(mid + a.size() - 1) % a.size()])
        {
            return mid;
        }
        else
        {
            // checking if the pivot is on the left side
            if (a[mid] > a[low] && a[mid] >= a[high])
                low = mid + 1;
            // checking if the pivot is on the right side
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {6, 7, 0, 1, 2, 3, 4, 5};
    cout << pivot_index(a) << endl;
    return 0;
}