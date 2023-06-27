//Unique rows in boolean matrix
//https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int n,m;
    cin>>n>>m;

    int a[MAX][MAX];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    vector<vector<int>> vec = uniqueRow(a,n,m);
    
    for(int i=0;i<vec.size();i++)
    {
        for(int x: vec[i])
            cout<<x<<" ";
        cout<<"$";
    }

    return 0;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>> ans;
    set<vector<int>> set;

    for (int i = 0; i < row; i++) {
        vector<int> v;
        for (int j = 0; j < col; j++) {
        v.push_back(M[i][j]);
        }

        if (set.find(v) == set.end()) {
        ans.push_back(v);
        set.insert(v);
        }
    }

    return ans;
}