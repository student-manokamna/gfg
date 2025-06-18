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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        int count=1;
        Node*temp=head;
        Node*prev=NULL;
        if(k==1)
        return NULL;
        while(temp){
           
          
            if(count==k){
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
                count=1;
                 }
                 else{
                       prev=temp;
              temp=temp->next;
            count++;
                 }
            
        }
        return head;
    }
};