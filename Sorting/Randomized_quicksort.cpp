#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r){
    int pivot = a[r];
    // swap(a[l],a[pivot]);
    int i=l-1,j=r+1;
    do{
        do{
            i++;
        }while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<j);
    swap(a[l],a[j]);
    return j;
}

int generateRandom(int a[],int l, int r){
    srand(time(NULL));
    //If random numbers are generated with rand() without first calling srand(), 
    //your program will create the same sequence of numbers each time it runs.
    int randNum = l + rand()%(r-l); 
    // Generate random number in range l to r
    swap(a[r],a[randNum]);
    return partition(a,l,r);
}
void quickSort(int a[],int l,int r){
    if(l<r){
        int p = generateRandom(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}