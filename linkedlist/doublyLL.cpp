#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* arr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    return head;
}

void printDLL(Node* head) {
    cout << "Forward: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    if(head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* tail=head;
    while(tail->next){
        tail=tail->next;
    }
    if (tail->prev) {
        Node* temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
        return head;
    } else {
        delete head;
        return nullptr;
    }
}
int main() {
    vector<int> arr = {1,2,3,4};
    Node* head = arr2DLL(arr);
    head=deleteHead(head);
    head=deleteTail(head);
    printDLL(head);
}
