#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Radix_sort(vector<int> &a){
    int n=a.size();
    int max=*max_element(a.begin(),a.end()); //find the largest element
    int exp=1;
    while(max/exp>0){ //loop until the largest element is less than the current exp
        vector<int> b(n); //create a temp array
        vector<int> count(10,0); //create a count array with 10 elements initialized to 0
        for(int i=0;i<n;i++) count[(a[i]/exp)%10]++; //store the count of each digit in the count array
        for(int i=1;i<10;i++) count[i]+=count[i-1]; //modify the count array such that each element at each index stores the sum of previous counts
        for(int i=n-1;i>=0;i--){ //store the elements in the temp array
            b[count[(a[i]/exp)%10]-1]=a[i];
            count[(a[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++) a[i]=b[i]; //copy the elements from the temp array to the original array
        exp*=10;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Radix_sort(a);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}