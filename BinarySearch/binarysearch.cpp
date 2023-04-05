#include<bits/stdc++.h>
using namespace std; 

int binary_search1(vector<int> v,int n){
    int high=v.size()-1;
    int low=0,mid=0;
    while(high-low>1){
        //cout<<mid<<endl;
        mid=(low+high)/2;
        if (v[mid]==n){
            return mid;
        }
        else if (v[mid]>n){
            high=mid-1;
        }
        else if (v[mid]<n){
            low=mid+1;
        }
    }
    if (v[low]==n){
        return low;
    }
    if (v[high]==n){
        return high;
    }
    else{
        cout<<"NOT FOUND"<<endl;
	return 0;
    }
}

int main(){
    vector<int> v={10,20,30,40,50,70};
    int n=80;
    cout<<binary_search1(v,n)<<endl;
}
