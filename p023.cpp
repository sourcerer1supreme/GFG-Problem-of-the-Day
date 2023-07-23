//Find triplets with zero sum
//https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1

#include<bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n);

int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findTriplets(arr,n);

    return 0;
}

bool findTriplets(int arr[], int n){
    sort(arr,arr+n);
    for(int i = 0;i<n-2;i++){
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum==0)
                return true;
            else if(sum<0)
                left++;
            else if(sum>0)
                right--;
        }
    }
    return false;
}
