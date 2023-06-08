#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    if (binary_search(a, a + n , 3))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}