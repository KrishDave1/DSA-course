#include <bits/stdc++.h>
using namespace std;

int count_occ(vector<int> v,int n){
    vector<int> :: iterator first1,last1;
    first1=lower_bound(v.begin(),v.end(),n);
    last1= upper_bound(v.begin(),v.end(),n);
    int first=first1-v.begin();
    int last=last1-v.begin();
    return last-first;
}

int main()
{
    vector<int> v = {10, 10, 50, 50, 50, 60};
    int n = 10;
    cout << count_occ(v,n) << endl;
}
