/*
||     Maximum Diamonds     ||
https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1
*/


#include<bits/stdc++.h>
using namespace std;

long long maxDiamonds(int A[], int N, int K);

int main()
{
    int N, K;
    cin>>N>>K;

    int A[N];

    for(int i=0; i<N; i++)
        cin>>A[i];
    
    cout << maxDiamonds(A,N,K) << endl;

    return 0;
}

long long maxDiamonds(int A[], int N, int K)
{
    priority_queue<int> p;

    for(int i=0;i<N;i++)
        p.push(A[i]);

    long long ans = 0;

    while (K-- && p.size())
    {
        int max = p.top();
        p.pop();

        ans+=max;

        if(max>1)
            p.push(max/2);
    }
    
    return ans;
}
