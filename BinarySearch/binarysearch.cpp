#include<bits/stdc++.h>
using namespace std; 

int binary_search(vector<int> v,int n){
    int high=v.size()-1;
    int low=0,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if (v[mid]==n)
            return mid;
        else if (v[mid]>n)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main(){
    vector<int> v={10,20,30,60,70};
    int n=30;
    cout<<binary_search1(v,n)<<endl;
}
