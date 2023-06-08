#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void deleteroot(vector<int> &v,int n){
    int i=0;
    int j=2*i+1;
    swap(v[0],v[n-1]);
    while(j<n-1){
        if(j+1<n && v[j+1]>v[j]){
            j=j+1;
        }
        if(v[i]<v[j]){
            swap(v[i],v[j]);
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
}

void insert(vector<int> &v,int n){
    v.push_back(n);
    int i=v.size()-1;
    while(i>0 && v[i/2]<v[i]){
        swap(v[i/2],v[i]);
        i=i/2;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v={};
    cout<<"Enter the elements of heap:"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(v,x);
    }
    cout<<"Heap is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        deleteroot(v,n-i);
    }
    cout<<"Sorted array"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}