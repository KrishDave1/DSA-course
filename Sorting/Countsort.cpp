#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void count_sort(vector<int> &a){
    int n=a.size();
    int max= *max_element(a.begin(),a.end());
    vector<int> c(max+1,0);
    int i=0;
    while(i<n){
        c[a[i++]]++;
    }
    i=0;
    int j=0;
    while(i<max+1){
        if (c[i]>0){
            a[j++]=i;
            c[i]--;
        }
        else i++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    count_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}