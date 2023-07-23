#include<bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k);

int main(){
    int n,i;
    long long int k;
    cin>>n>>k;

    vector<int> arr(n);
    for(i=0;i<n;i++)
        cin>>arr[i];

    cout<<countSubArrayProductLessThanK(arr,n,k)<<endl;

    return 0;
}

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k){
    int count = 0;
    long long product = 1;
    int left = 0;

    for(int right = 0; right < n; right++){
        product*=a[right];

        while(product>=k && left<=right){
            product/=a[left];
            left++;
        }

        count += right - left + 1; 
    }

    return count;
}
