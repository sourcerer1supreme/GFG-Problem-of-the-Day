//Number of 1 Bits
//https://practice.geeksforgeeks.org/problems/set-bits0143/1

#include<bits/stdc++.h>
using namespace std;

int setBits(int N);

int main()
{
    int n;
    cin>>n;
    cout<<setBits(n)<<endl;

    return 0;
}

int setBits(int N)
{
    int count = 0;
    while(N){
        if(N & 1)
            count++;
        N>>=1;
    }
    return count;
}
