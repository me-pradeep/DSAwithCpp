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

Node* reverseDLL(Node* head){
    Node* curr = head;
    Node* back=nullptr;
    while(curr){
        back=curr->prev;
        curr->prev=curr->next;
        curr->next=back;
        curr=curr->prev; //because now next become prev for this node
    }
    return back->prev; //because for DLL :- [ x <-> y <-> z <-> nullptr ] for nullptr , back is y and y ka back is z
}

int main() {
    vector<int> arr = {1,2,3,4};
    Node* head = arr2DLL(arr);
    head= reverseDLL(head);
    printDLL(head);
}
