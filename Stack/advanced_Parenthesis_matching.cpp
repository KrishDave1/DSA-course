#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int parenthesis(string s){
    stack <char> a;
    int x;
    for(int i=0;i<s.length();i++){
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')
        a.push(s[i]);
        else if (s[i]==')' || s[i]==']' || s[i]=='}'){
            if (a.empty())
            return 0;
            x=a.top();
            a.pop();
            if (x=='('){
                if (s[i]=='}' || s[i]==']')
                return 0;
            }
            else if (x=='{'){
                if (s[i]==')' || s[i]==']')
                return 0;
            }
            else if (x=='['){
                if (s[i]=='}' || s[i]==')')
                return 0;
            } 
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