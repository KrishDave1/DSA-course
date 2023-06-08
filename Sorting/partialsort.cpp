#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,4,5,3,9,0,8,11,6,10,13};
    std :: sort(a.begin(), a.begin()+4);
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}