//Maximum Index
//https://practice.geeksforgeeks.org/problems/maximum-index3307/1

#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0;i < n;i++)
        cin >> a[i];

    cout << maxIndexDiff(a,n);

    return 0;
}

int maxIndexDiff(int arr[], int n)
{
    int maxDiff = 0;
    int leftMin[n], rightMax[n];

    leftMin[0] = arr[0];
    for(int i = 1; i < n; i++)
        leftMin[i] = min(arr[i],leftMin[i-1]);

    rightMax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        rightMax[i] = max(arr[i],rightMax[i+1]);    

    int i=0, j=0;
    while (i<n && j<n){
        if(leftMin[i]<=rightMax[j]){
            maxDiff = max(maxDiff, j-i);
            j++;
        }
        else
            i++;
    }
    return maxDiff;
}
