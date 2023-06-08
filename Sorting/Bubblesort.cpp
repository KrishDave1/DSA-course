#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) // for loop to iterate over the array
    {
        int flag = 0;                       // flag to check if the array is sorted or not
        for (int j = 0; j < n - i - 1; j++) // for loop to iterate over the array
        {
            if (a[j] > a[j + 1]) // if the current element is greater than the next element then swap them
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) // if the flag is 0 then the array is sorted so break the loop
        {
            break;
        }
    }
}crr5zfx

int main()
{
    int a[] = {5, 3, 4, 1, 2};        // declare the array
    int n = sizeof(a) / sizeof(a[0]); // get the size of the array
    Bubblesort(a, n);                 // call the function to sort the array
    for (int i = 0; i < n; i++)       // for loop to iterate over the array
    {
        cout << a[i] << " "; // print the array
    }
    cout << endl;

    return 0;
}
