//Remove duplicates from an unsorted linked list
//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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

Node * removeDuplicates(Node *head);
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

    removeDuplicates(head);

    cout<<endl;
    printList(head);

    return 0;
}

Node* removeDuplicates( Node *head){
    
    unordered_map<int,int> dupMap;
    Node* current = head;
    Node* prev = current;

    dupMap[current->data]++;
    current = current->next;
    
    while(current!=NULL){
        if(dupMap[current->data]){
            Node* temp = current;
            prev->next = current->next;
            current = current -> next;
            free(temp);
        }
        else{
            dupMap[current->data]++;
            prev = current;
            current = current -> next;
        }
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