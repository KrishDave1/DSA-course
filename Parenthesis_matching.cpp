#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int parenthesis(string s){
    stack <char> a;
    for(int i=0;i<s.length();i++){
        if (s[i]=='(')
        a.push(s[i]);
        else if (s[i]==')'){
            if (a.empty())
            return 0;
            a.pop();
        }
    }
    if (a.empty()){
        return 1;
    }
    else
    return 0;

}
//2 imp things to note here 
// 1) stack is of data type char. 
// 2) top method should be 0 and not -1(only for stl case).
 
int main(){
    string d;
    cin>>d;
    cout<<parenthesis(d)<<endl;
    return 0;
}