#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// stack<char> b;

int pre(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    return 0;
}

int isoperand(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
    {
        return 0;
    }
    else
        return 1;
}
string postfix(string infix)
{
    // cout<<1;
    stack<char> b;
    string pos;
    int j = 0;
    for (int i=0;i < infix.length();i++)
    {
        if (isoperand(infix[i]))
        {
            pos.push_back(infix[i++]);
        }
        else
        {
            if (pre(infix[i]) > pre(b.top()))
            {
                b.push(infix[i++]);
            }
            else
            {
                while (!b.empty()
                   && pre(infix[i]) <= pre(b.top())) {
                pos += b.top();
                b.pop();
            }
            b.push(c);
                // pos[j++] = b.top();
                // b.pop();
            }
        }
    }

    while (!b.empty())
    {
        pos.push_back(b.top());
        b.pop();
    }
    // cout << pos;
    return pos;
}
int main()
{
    string c;
    cin >> c;
    b.push('#');
    string d = postfix(c);
    cout << d << endl;
    return 0;
}