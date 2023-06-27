//https://practice.geeksforgeeks.org/problems/reverse-coding2452/1
//You will be given an integer n, your task is to return the sum of all natural number less than or equal to n. As the answer could be very large, return answer modulo 10^9+7.

#include<bits/stdc++.h>
using namespace std;

int sumOfNaturals(int n);

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"The sum of all natural numbers till "<<n<<" is: "<<sumOfNaturals(n);

    return 0;
}

int sumOfNaturals(int n)
{
    const int mod = 1e9+7;
    long long sum = 1LL*n*(n+1)/2;
    return sum % mod;
}

/* return ((long)n*(n+1)/2) % (long)(1e9+7); */