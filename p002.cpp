//https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k);

int main() {


    int n, k;
    cin>>n>>k ;

    int arr[n];
    for (int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> ans = kLargest(arr, n, k);
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
}

vector<int> kLargest(int arr[], int n, int k)
{
    sort(arr,arr+n);
    
    vector<int> ans;
    for(int i = n-1;i>=n-k;i--)
        ans.push_back(arr[i]);

    return ans;
}   
