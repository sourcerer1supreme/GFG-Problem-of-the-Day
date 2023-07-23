//Union of Two Linked Lists
//https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1

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
};

struct Node* buildList(int size);
void printList(Node* n);
struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int n, m;

    cin>>n;
    Node* first = buildList(n);

    cin>>m;
    Node* second = buildList(m);

    Node* head = makeUnion(first,second);
    printList(head);

    return 0;
}


struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node (val);
    Node* tail = head;
    for(int i = 0;i<size-1;i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout << n->data <<" ";
        n = n -> next;
    }
    cout << endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s;
    Node *current;

    current = head1;
    while(current){
        s.insert(current->data);
        current = current->next;
    }

    current = head2;
    while(current){
        s.insert(current->data);
        current = current->next;
    }

    Node* head3 = new Node(-1);     // dummy node
    Node* last = head3;

    for(auto element : s){
        last->next = new Node(element);
        last = last->next;
    }

    head3 = head3->next;           // bypassing the dummy node

    return head3;
}
