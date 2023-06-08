#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Merge_single_array(int a[],int l,int mid,int h);
void Recursive_Merge_sort(int a[],int l,int h);
void Merge_single_array(int a[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++]=a[i];
    }
    for(;j<=h;j++){
        b[k++]=a[j];
    }
    for(int i=l;i<=h;i++){
        a[i]=b[i];
    }
}

void Recursive_Merge_sort(int a[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        Recursive_Merge_sort(a,l,mid);
        Recursive_Merge_sort(a,mid+1,h);
        Merge_single_array(a,l,mid,h);
    }
}

int main(){
    int a[] = {5, 3, 4, 1, 2}; //declare the array
    int n = sizeof(a) / sizeof(a[0]); //get the size of the array
    Recursive_Merge_sort(a, 0, n); //call the function to sort the array
    for (int i = 0; i < n; i++) //for loop to iterate over the array
    {
        cout << a[i] << " "; //print the array
    }
    cout << endl;

    return 0;
}