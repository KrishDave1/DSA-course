#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) //for loop to iterate over the array
    {
        int k = i;
        for (int j = i + 1; j < n; j++) //for loop to iterate over the array
        {
            if (a[j] < a[k]) //if the current element is smaller than the current minimum then assign the current element to the current minimum
            {
                k = j;
            }
        }
        swap(a[i], a[k]); //swap the current element with the current minimum
    }
}

int main(){
    int a[] = {5, 3, 4, 1, 2}; //declare the array
    int n = sizeof(a) / sizeof(a[0]); //get the size of the array
    Selectionsort(a, n); //call the function to sort the array
    for (int i = 0; i < n; i++) //for loop to iterate over the array
    {
        cout << a[i] << " "; //print the array
    }
    cout << endl;
    return 0;
}