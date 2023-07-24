// Right View of Binary Tree
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> rightView(Node *root);
Node* buildTree(string str);

int main(){
    string s;
    getline(cin, s) ;
    Node* root = buildTree(s);
    vector<int> vec = rightView(root);
    for(int x : vec){
        cout<<x<<" ";
    }
    cout << endl;

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

vector<int> rightView(Node* root){
    
    vector<int> rightViewNodes;

    if(root==NULL)
        return rightViewNodes;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int len = q.size();

        for (int i = 0; i < len; i++) {
            Node* node = q.front();
            q.pop();

            if (i == len - 1) {
                rightViewNodes.push_back(node->data);
            }

            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return rightViewNodes;
}