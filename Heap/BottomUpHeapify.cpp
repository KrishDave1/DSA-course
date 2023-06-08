#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Bottomupheapify (int a[],  int i){  
    int p = (i - 1) / 2;  
    while (1){ 
        if (a[i] > a[p])	{	  
            swap(a[i],a[p]);
            i=p;	 
            p=(i - 1) / 2;	
        }
        else
            break;    
        if (i == 0)
            break;
    }
}

void heapcreate(int arr[],int n){
    for(int i = 1; i < n ; i++)
        Bottomupheapify(arr, i);
}

int main(){
    int arr[] = {7, 5, 20, 2, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapcreate(arr,n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}