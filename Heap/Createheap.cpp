#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int n){
    v.push_back(n);
    int i=v.size();
    while(i>0 && v[(i)/2]<v[i]){
        swap(v[i/2],v[i]);
        i=(i-1)/2 + 1;
    }
}

int main(){
    vector<int> v={};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(v,x);
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}