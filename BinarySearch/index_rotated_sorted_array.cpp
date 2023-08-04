#include <iostream>
#include <bits/stdc++.h>
using namespace std;

def rotated_array_index(v, n):
    # Find the pivot index
    pivot = pivot_index(v)
    # Search the segment of the array from index 0 to pivot - 1
    i1 = binary_search1(v, n, 0, pivot - 1)
    # Search the segment of the array from pivot to index len(v) - 1
    i2 = binary_search2(v, n, pivot, len(v) - 1)
    # Return the index if found in either of the segments
    if i1 != -1:
        return i1
    elif i2 != -1:
        return i2
    # Else, return -1
    else:
        return -1

def pivot_index(v):
    # Find the pivot index
    pivot = 0
    for i in range(len(v)):
        if v[i] < v[pivot]:
            pivot = i
    return pivot

def binary_search1(v, n, l, r):
    # Search the segment of the array from index 0 to pivot - 1
    while l <= r:
        mid = (l + r) // 2
        if v[mid] == n:
            return mid
        elif v[mid] < n:
            l = mid + 1
        else:
            r = mid - 1
    return -1

def binary_search2(v, n, l, r):
    # Search the segment of the array from pivot to index len(v) - 1
    while l <= r:
        mid = (l + r) // 2
        if v[mid] == n:
            return mid
        elif v[mid] < n:
            l = mid + 1
        else:
            r = mid - 1
    return -1

int main()
{
    vector<int> a = {6, 7, 0, 1, 2, 3, 4, 5};
    cout << rotated_array_index(a,4) << endl;
    return 0;
}