//Kth Ancestor in a Tree
//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* buildTree(string str);
int kthAncestor(Node *root, int k, int node);

int main(){
    int k, node;
    cin>>k>>node;
    string s;
    getline(cin, s) ;
    Node* root = buildTree(s);
    cout<<kthAncestor(root,k,node);
    return 0;
}

Node* buildTree(string str){
    
    if(str.length()==0 || str[0] == 'N')
        return NULL;
    
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while( !q.empty() && i < ip.size()) {
        
        Node* currNode = q.front(); 
        q.pop();
        
        string currVal = ip[i];

        if(currVal!="N"){
            currNode->left = new Node(stoi(currVal));
            q.push(currNode -> left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal!="N"){
            currNode->right = new Node(stoi(currVal));
            q.push(currNode -> right);
        }
        i++;
    }

    return root;
}

void help(Node* root, int k, int node, int &ans, vector<int> &temp){
    if(!root)
        return;
    if(root->data==node && temp.size()>=k){
        ans = temp[temp.size()-k];
        return;
    }
    temp.push_back(root->data);
    help(root->left,k,node,ans,temp);
    help(root->right,k,node,ans,temp);
    temp.pop_back();
}

int kthAncestor(Node *root, int k, int node){
    vector<int> temp;
    int ans = -1;
    help(root,k,node,ans,temp);
    return ans;
}