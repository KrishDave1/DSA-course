#include<iostream>
#include<bits/stdc++.h>
using namespace std;


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

void Iterative_Merge_sort(int a[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge_single_array(a,l,mid,h);
        }
    }
    if(p/2<n){
        Merge_single_array(a,0,p/2-1,n-1);
    }
}


int main(){
    int a[]={5,3,4,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    Iterative_Merge_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}