//Reverse a Linked List in groups of given size
//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
} *head;

struct node *reverse (struct node *head, int k);
void printList(struct node *head);

int main(){
    struct node* head = NULL;
    struct node* temp = NULL;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        if(i==0){
            head = new node(value);
            temp = head;
        }
        else{
            temp->next = new node(value);
            temp = temp->next; 
        }
    }

    int k;
    cin >> k;

    printList(head);

    reverse(head,k);

    cout<<endl;
    printList(head);

    return 0;
}

struct node *reverse (struct node *head, int k){
    struct node *temp = head;
    int len=0;                          // calculating length of the linked list
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }

    int numOfGroups = len/k + 1;        //calculating number of groups formed

    temp = head;
    while(numOfGroups--){
        int k1 = k;
        struct node* groupHead = temp;
        
        stack<int> s;

        while(temp!=NULL && k1--){      //push all the elements of a group in a stack
            s.push(temp->data);
            temp=temp->next;
        }

        while(!s.empty()){              //pop the elements and  overwrite the previous elements in a group
            groupHead -> data = s.top();
            s.pop();
            groupHead = groupHead -> next;
        }
    }

    return head;
}

void printList(struct node *head){
    struct node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
}