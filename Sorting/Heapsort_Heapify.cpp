#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TOP DOWN APPROACH

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // finding left and right child using index formula
    int r = 2*i + 2; 

    // If left child is larger than root and l is less than size of array.
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest); 
    }
}

void heapcreate(int arr[],int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heap_sort(int arr[],int n){
    heapcreate(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    
    return 0;
}