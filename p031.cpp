// Queue Reversal
// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q);

int main(){
    queue<int> q;
    int n;
    int var;

    cin>>n;
    while(n--){
        cin>>var;
        q.push(var);
    }
    
    queue<int> a = rev(q);

    while(!a.empty()){
        cout<<a.front()<<" ";
        a.pop();
    }

    return 0;
}

queue<int> rev(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    return q;
}
