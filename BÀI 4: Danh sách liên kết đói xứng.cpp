Cách 1: sử dụng stack (Bộ nhớ O(n))

// palindrome linked list
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    stack<int> s;
    
    while (fast != nullptr && fast->next != nullptr) {
        s.push(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if (fast != nullptr) slow = slow->next; // bo qua node chinh giua (neu co) vi node chinh giua khong co node doi xung
    while (slow != nullptr) {
        int curr = s.top();
        s.pop();
        
        if (curr != slow->val) {
            return false;
        }
        slow = slow->next;
    }
        
    return true;
}


Cách 2: Đảo ngược nửa sau của danh sách liên kết


// ham phu tro: dao nguoc danh sach (tu giua den cuoi)
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// palindrome linked list
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;
        
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    ListNode* secondHalf = reverseList(slow);
    ListNode* firstHalf = head;
    
    ListNode* p = secondHalf;
    while (p != nullptr) {
        if (p->val != firstHalf->val) {
            return false;
        }
        
        // di chuyen den node ke tiep
        p = p->next;
        firstHalf = firstHalf->next;
    }
    
    // co the dao nguoc lai de dam bao tinh toan ven du lieu
    
    return true;
}
