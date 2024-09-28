
class Solution {
  public:
  
    Node* insertAtTail(Node* &tail,int val){
        
        Node* temp = new Node(val);
        tail->next = temp;
        tail = temp;
        return tail;
    }
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zeroTail = zeroHead;
        Node* oneTail = oneHead ;
        Node* twoTail = twoHead;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                insertAtTail(zeroTail, 0);
            }
            else if(temp->data == 1){
                insertAtTail(oneTail, 1);
            }
            else{
                insertAtTail(twoTail, 2);
            }
            
            temp = temp->next;
        }
        
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
            
        }
        else{
            zeroTail->next = twoHead->next;
            
        }
        
        twoTail->next = NULL;
        head = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};
