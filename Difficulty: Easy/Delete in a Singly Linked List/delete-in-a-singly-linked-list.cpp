/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(!head)
        return NULL;
        if(head->next==NULL){
            head=NULL;
            return head;
        }
        
        if(x==1){
            Node*temp=head;
            head=head->next;
            delete temp;
            return head;
            
        }
        Node*prev=NULL;
        Node*temp=head;
        while(--x){
            prev= temp;
            temp=temp->next;
        }
        if(temp->next==NULL){
            prev->next=NULL;
            delete temp;
         
        }
       else{
           prev->next=temp->next;
           delete temp;
          
          
       }
       return head;
        
    }
};