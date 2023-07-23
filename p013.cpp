//Maximum Depth Of Binary Tree
//https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str){

    if (str.length() == 0 || str[0]== 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        
        Node* currNode = queue.front() ;
        queue.pop() ;
        
        string currVal = ip[i];
        
        if (currVal != "N") {
            currNode -> left = newNode(stoi(currVal));
            queue.push(currNode -> left) ;
        }

        i++;
        if (i >= ip.size()) break;
        
        currVal = ip[i];
        if (currVal != "N"){
            currNode->right = newNode(stoi (currVal));
            queue.push (currNode -> right) ;
        }
        i++;
    }

    return root;
}

int maxDepth(Node *root){
    if(root==NULL)
        return 0;
    else{
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth,rightDepth) + 1;
    }
}

int main()
{
    string s, ch;
    getline(cin, s);
    
    Node* root = buildTree(s);
    
    cout << maxDepth(root) << endl;

    return 0;
}
