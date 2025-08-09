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

Node* removeTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node* removeKth(Node* head , int k){
    if(head==nullptr)return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=nullptr;

    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeVal(Node* head , int val){
    if(head==nullptr)return head;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int tempVal;
    Node* temp=head;
    Node* prev=nullptr;

    while(temp!=nullptr){
        tempVal=temp->data;
        if(tempVal==val){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,5,8,9};
    Node* head=Arr2LL(arr);
    head=removeVal(head,8);
    printLL(head);
}