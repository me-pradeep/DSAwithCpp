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

Node* removeHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

void removeTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}

int main(){
    vector<int> arr={1,2,3,5,8,9};
    Node* head=Arr2LL(arr);
    removeTail(head);
    printLL(head);
}