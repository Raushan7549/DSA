// https://www.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class Insert_in_a_Sorted_List{
    public:
    Node* sortedInsert(Node* head,int key){
        Node* newnode = new Node(key);
        if(head == nullptr)  return newnode;

        if(head->data >= key){
            newnode->next = head;
            return newnode;
        }

        Node* curr = head;

        while(curr->next != nullptr && curr->next->data < key){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;

        return head;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int n;
    cout <<"Enter number of elements in sorted list: ";
    cin >> n;

    Node* head = nullptr;
    cout<< "Enter elements in sorted order:\n";
    for (int i = 0; i<n;i++){
        int val;
        cin>>val;

        Node* newnode = new Node(val);

        if(head == nullptr){
            head= newnode;
        } else {
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    int key;
    cout << "Enter value to insert: ";
    cin >> key;

    Insert_in_a_Sorted_List obj;
    head = obj.sortedInsert(head, key);

    cout << "Updated Linked List:\n";
    printList(head);

    return 0;

}
