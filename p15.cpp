//Is Binary Number Multiple of 3
//https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-30654/1

#include<bits/stdc++.h>
using namespace std;

int isDivisible(string s);

int main()
{
    string s;
    cin>>s;
    cout<<isDivisible(s)<<endl;

    return 0;
}

int isDivisible(string s)
{
    char state = 'a';
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='0' && state=='a')
            state='a';
        else if(s[i]=='1' && state=='a')
            state='b';
        else if(s[i]=='0' && state=='b')
            state='c';
        else if(s[i]=='1' && state=='b')
            state='a';
        else if(s[i]=='0' && state=='c')
            state='b';
        else if(s[i]=='1' && state=='c')
            state='c';
    }
    
    if(state=='a')
        return 1;
    else 
        return 0;
}