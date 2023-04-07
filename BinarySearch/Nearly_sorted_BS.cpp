#include<bits/stdc++.h>
using namespace std; 

int binary_search(vector<int> v,int n){
    int high=v.size()-1;
    int low=0,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if (v[mid]==n)
            return mid;
        if (v[mid+1]==n && mid+1<=high)
            return mid+1;
        if (v[mid-1]==n && mid-1>=low)
            return mid-1;
        else if (v[mid]>n)
            high=mid-2;
        else
            low=mid+2;
    }
    return -1;
}

int main(){
    vector<int> v={10,20,60,30,70};
    int n=30;
    cout<<binary_search(v,n)<<endl;
}
