//Given a linked list of 0s, 1s and 2s, sort it
//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
} *head;

Node* segregate( Node *head);
void printList(struct Node *head);

int main(){
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        if(i==0){
            head = new Node(value);
            temp = head;
        }
        else{
            temp->next = new Node(value);
            temp = temp->next; 
        }
    }

    printList(head);

    segregate(head);

    cout<<endl;
    printList(head);

    return 0;
}

Node* segregate( Node *head){
    
    unordered_map<int,int> count;
    Node* current = head;
    
    while(current!=NULL){
        count[current->data]++;
        current = current -> next;
    }

    current = head;

    while(count[0]--){
        current->data = 0;
        current = current -> next;
    }

    while(count[1]--){
        current->data = 1;
        current = current -> next;
    }

    while(count[2]--){
        current->data = 2;
        current = current -> next;
    }
    
    return head;
}

void printList(struct Node *head){
    struct Node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}