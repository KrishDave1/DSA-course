#include<bits/stdc++.h>
using namespace std; 

int binary_search(vector<int> v,int n){
    int high=v.size()-1;
    int low=0,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if (v[mid]<=n && v[mid+1]>n)
            return mid;
        else if (v[mid]>n)
            high=mid;   
        else if (v[mid]<n && v[mid+1]<n)
            low=mid;
    }
    return -1;
}

int main(){
    vector<int> v={1,3,5,6};
    int n=5;
    cout<<binary_search(v,n)<<endl;
}
