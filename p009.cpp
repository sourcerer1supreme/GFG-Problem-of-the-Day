//Prefix match with other strings
//https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1

#include<bits/stdc++.h>
using namespace std;

int klengthpref(string arr[], int n, int k, string str);

int main()
{
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    string str;
    cin >> str;

    cout<< klengthpref(arr,n,k,str);

    return 0;
}

int klengthpref(string arr[], int n, int k, string str)
{
    int count = 0;

    if(str.length() < k)
        return 0;

    string subs = str.substr(0,k);
    
    for(int i=0;i<n;i++)
        if(!subs.compare(arr[i].substr(0,k)))
            count++;
    
    return count;
}
