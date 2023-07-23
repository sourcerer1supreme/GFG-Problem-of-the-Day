//Matchsticks game
//https://practice.geeksforgeeks.org/problems/-matchsticks-game4906/1

#include<bits/stdc++.h>
using namespace std;

int matchGame(long long N);

int main()
{
    long long n;
    cin>>n;

    cout<<matchGame(n);

    return 0;
}

int matchGame(long long N)  
{                   // A's choice + B's choice = 5.
    if(N%5==0)      // If N is a multiple of 5, player A loses no matter what.
        return -1;
    else
        return N%5; // If A starts with the remainder, then B can never reach the end first.
}
