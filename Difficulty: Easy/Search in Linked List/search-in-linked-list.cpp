/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        vector<int>arr;
        Node*temp=head;
        while(temp!=NULL){
            arr.push_back(temp->data);
         
            temp=temp->next;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==key)
            return true;
        }
        return false;
    }
};
