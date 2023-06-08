#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int arr[] = {7, 5, 20, 2, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}