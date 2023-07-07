//Merge Without Extra Space
//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include<bits/stdc++.h>
using namespace std;

void swap(long long *x, long long *y);
void merge(long long arr1[], long long arr2[], int n, int m);

int main(){
    int n, m;
    cin >> n >> m;
    long long arr1[n], arr2[m];

    for(int i=0;i<n;i++)
        cin >> arr1[i];

    for(int i=0;i<m;i++)
        cin >> arr2[i];

    merge(arr1,arr2,n,m);

    for(int i=0;i<n;i++)
        cout << arr1[i] << " ";

    for(int i=0;i<m;i++)
        cout << arr2[i] << " ";  

    cout<<endl;

    return 0;  
}

void merge(long long arr1[], long long arr2[], int n, int m){
    int i = n - 1;
    int j = 0;

    while(i>-1 && j<m){
        if(arr1[i]>arr2[j])
            swap((arr1+i),(arr2+j));
        i--;
        j++;
    }

    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

void swap(long long *x, long long *y){
    long long t;
    t = *x;
    *x = *y;
    *y = t;
}