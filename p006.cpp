//Rearrange an array with O(1) extra space
//https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

#include<bits/stdc++.h>
using namespace std;

void arrange(long long arr[], int n);

int main()
{
    int n;
    cin>>n;

    long long A[n];

    for(int i = 0;i < n;i++)
        cin >> A[i];

    arrange(A,n);

    for(int i = 0;i < n;i++)
        cout << A[i] <<" ";
}

void arrange(long long arr[], int n)
{
    long long num;
    for(int i = 0;i < n;i++)
    {
        num = arr[arr[i]];
        for(int j = 0;j < 17;j++)
            if((num>>j) & 1)                 // if the jth bit is set in the required number
                arr[i] |= (1LL << (j + 17));  // also set the j+17th bit in the modified number
    }

    for(int i = 0;i < n;i++)
        arr[i] >>= 17;                      // right shift 17 times to overwrite the old number.
}
