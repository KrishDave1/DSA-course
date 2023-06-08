#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++) //for loop to iterate over the array
    {
        int x = a[i]; //assign the current element to a variable
        int j = i - 1; //assign the previous index to a variable
        while (j > -1 && a[j] > x) //while loop to iterate over the array
        {
            a[j + 1] = a[j]; //move the current element to the next index
            j--; //decrement the index
        }
        a[j + 1] = x; //assign the current element to the current index
    }
}

int main(){
    int a[] = {5, 3, 4, 1, 2}; //declare the array
    int n = sizeof(a) / sizeof(a[0]); //get the size of the array
    Insertionsort(a, n); //call the function to sort the array
    for (int i = 0; i < n; i++) //for loop to iterate over the array
    {
        cout << a[i] << " "; //print the array
    }
    cout << endl;

    return 0;
}

