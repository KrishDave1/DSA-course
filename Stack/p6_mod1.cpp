#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_subarray(int *a, int *b, int x, int y)
{
    int count[1000] = {0};
    int o = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (b[j] == a[i])
            {
                for (int k = j, l = i; k < y && l < i; k++, l++)
                {
                    if (b[k] == a[l])
                    {
                        count[o]++;
                    }
                }
                o++;
            }
        }
    }
    // cout << o << endl;
    for (int i = 0; i <= o; i++)
    {
        cout << count[o] << " ";
    }
}

int main()
{
    int x, y, a[1000] = {0}, b[1000] = {0};
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    cin >> y;
    for (int i = 0; i < x; i++)
    {
        cin >> b[i];
    }
    max_subarray(a, b, x, y);
    return 0;
}