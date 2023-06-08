#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int Partition(int a[],int l,int h)
{
    int pivot = a[l]; //assign the first element to a variable
    int i = l, j = h; //assign the first index to i and the last index to j
    do
    {
        do
        {
            i++; //increment the index
        } while (a[i] <= pivot); //while loop to iterate over the array
        do
        {
            j--; //decrement the index
        } while (a[j] > pivot); //while loop to iterate over the array
        if (i < j) //if the current index is less than the current minimum then swap them
        {
            swap(a[i], a[j]);
        }
    } while (i < j); //while loop to iterate over the array until the current index is less than the current minimum
    swap(a[l], a[j]); //swap the first element with the current minimum
    return j; //return the current minimum
}

void Quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=Partition(a,l,h); //assign the current minimum to a variable
        Quicksort(a,l,j); //recursive call to the function with the starting index as the start of the array and the ending index as the current minimum
        Quicksort(a,j+1,h); //recursive call to the function with the starting index as the current minimum and the ending index as the end of the array
    }
}


int main(){
    int a[] = {5, 3, 4, 1, 2}; //declare the array
    int n = sizeof(a) / sizeof(a[0]); //get the size of the array
    Quicksort(a, 0, n); //call the function to sort the array
    for (int i = 0; i < n; i++) //for loop to iterate over the array
    {
        cout << a[i] << " "; //print the array
    }
    cout << endl;
    return 0;
}