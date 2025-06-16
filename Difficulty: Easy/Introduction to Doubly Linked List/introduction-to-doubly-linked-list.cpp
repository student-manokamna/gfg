// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
          Node*head=new Node(arr[0]);
          Node*curr= head;
          Node*front=NULL;
    
            
            int i=1;
         while( i<arr.size()){
             Node*temp= new Node(arr[i]);
            curr->next=temp;
            temp->prev=curr;
            front = temp->next;
             
             curr=temp;
             i++;
         }
         return head;
    }
};