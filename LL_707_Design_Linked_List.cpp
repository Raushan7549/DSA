// 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/description/

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class MyLinkedList {
public:

    Node* head;
    int cnt;

    MyLinkedList() {
        head = nullptr;
        cnt = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= cnt){
            return -1;
        }

        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);

        if(head==nullptr){
            head = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }

        cnt++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }

        cnt++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>cnt)  return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == cnt){
            addAtTail(val);
            return;
        }

        Node* newnode = new Node(val);
        Node* temp = head;

        for(int i=0;i<index-1; i++){
            temp = temp->next;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        temp->next->prev = newnode;
        temp->next = newnode;

        cnt++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= cnt)   return;

        if(index == 0){
            Node* temp = head;
            head = head->next;

            if(head != nullptr){
                head->prev = nullptr;
            }

            delete temp;
            cnt--;
            return;
        }

        Node* temp = head;

        for(int i=0;i<index; i++){
            temp = temp->next;
        }

        temp->prev->next = temp->next;

        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        delete temp;
        cnt--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
