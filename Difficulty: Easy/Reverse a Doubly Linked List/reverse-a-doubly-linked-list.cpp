/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
         if (!head || !head->next) return head; 
        DLLNode* temp=head;
        DLLNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        while(temp!=curr  && temp->prev != curr){
          int val= temp->data;
            temp->data=curr->data;
            curr->data=val;
            temp=temp->next;
            curr=curr->prev;
        }
        return head;
    }
};