//nCr
//https://practice.geeksforgeeks.org/problems/ncr1019/1

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r);

int main()
{
    int n,r;
    cin >> n >> r;

    cout<<nCr(n,r);

    return 0;
}

int nCr(int n, int r)
{
    if(r>n)
        return 0;

    if(r==n || r==0)
        return 1;

    int dp[r+1] = {0};
    dp[0] = 1;
    int mod = 1e9+7;

    for(int i=1;i<=n;i++)
        for(int j = min(i,r);j > 0;j-- ){
            dp[j]=(dp[j]+dp[j-1])%mod;
        }

    return dp[r];
}
