//Lowest Common Ancestor in a BST
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

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
Node* LCA(Node *root, int n1, int n2);
Node* traverse(Node *root, int n1, int n2);

int main(){
    int n1, n2;
    cin>>n1>>n2;
    string s;
    getline(cin, s) ;
    Node* root = buildTree(s);
    cout<<LCA(root,n1,n2)->data;
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

Node* LCA(Node *root, int n1, int n2){
    return traverse(root,n1,n2);
}

Node* traverse(Node *root, int n1, int n2){

    if(n1 < root->data && n2 < root->data)
        traverse(root->left,n1,n2);
    else if(n1 > root->data && n2 > root->data)
        traverse(root->right,n1,n2);
    else
        return root;
}