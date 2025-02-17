class Solution {
    public:
    
        ListNode* merge(ListNode* left, ListNode* right) {
            if (!left) return right;
            if (!right) return left;
    
            ListNode* dummy = new ListNode();  
            ListNode* temp = dummy;
    
            while (left && right) {
                if (left->val < right->val) {
                    temp->next = left;
                    left = left->next;
                } else {
                    temp->next = right;
                    right = right->next;
                }
                temp = temp->next;
            }
    
      
            if (left) temp->next = left;
            if (right) temp->next = right;
    
            return dummy->next;
        }
        ListNode* findMiddle(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
    
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
    
            if (prev) prev->next = nullptr;  
            return slow;
        }
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head; 
    
            ListNode* mid = findMiddle(head);
            ListNode* left = sortList(head); 
            ListNode* right = sortList(mid);   
    
            return merge(left, right); 
        }
    };
    