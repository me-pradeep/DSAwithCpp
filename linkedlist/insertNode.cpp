#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* Arr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}

Node* insertHead(Node* head , int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
    return head;
}

Node* insertTail(Node* head , int val){
    if(head==nullptr){
        head=new Node(val);
        return head;
    }
    Node* newNode=new Node(val);
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

Node* insertAtPosition(Node* head, int val, int k) {
    if (k <= 1 || head == nullptr) {
        return insertHead(head, val);
    }
    Node* temp = head;
    int count = 1;
    while (temp && count < k - 1) {
        temp = temp->next;
        count++;
    }
    Node* newNode = new Node(val);
    if (temp == nullptr) {
        return insertTail(head, val);
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertBeforeValue(Node* head, int val, int el) {
    if (head == nullptr || head->data == el) {
        return insertHead(head, val);
    }
    Node* temp = head;
    while (temp->next && temp->next->data != el) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    if (temp->next == nullptr) {
        return insertTail(head, val);
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main(){
    vector<int> arr={1,2,3,5,8,9};
    Node* head=Arr2LL(arr);
    head=insertHead(head , 15);
    head=insertTail(head,20);
    head=insertAtPosition(head, 99, 4);
    head=insertBeforeValue(head, 77, 8);
    printLL(head);
}