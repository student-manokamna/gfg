/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(head==NULL)
        return NULL;
        if(head->next==NULL){
            head=NULL;
            return head;
        }
        
        if(x==1){
           Node*temp=head;
           head=head->next;
          if(head!=NULL)
          head->prev=NULL;
           delete temp;
           return  head;
        }
        Node*temp=head;
        Node*prev=NULL;
        while(--x && temp!=NULL){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        return head;
        prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=prev;
        }
     
        delete temp;
        return head;
     
    }
};