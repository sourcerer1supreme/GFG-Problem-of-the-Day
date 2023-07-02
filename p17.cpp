//Copy Set Bits in Range
//https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1

#include<bits/stdc++.h>
using namespace std;

int setSetBit(int x, int y, int l, int r);

int main()
{
    int x,y,l,r;
    cin>>x>>y>>l>>r;
    cout<<setSetBit(x,y,l,r);

    return 0;
}

int setSetBit(int x, int y, int l, int r)
{
    int mask = ((1<<(r-l+1))-1)<<(l-1);
    x = x | (y & mask);

    return x;
}