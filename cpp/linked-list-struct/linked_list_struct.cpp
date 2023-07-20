#include <iostream>
#include "linked_list_struct.hpp"


void print_list(Node* head) {

    if(head != nullptr) {

        while(head != nullptr) {

            std::cout << head->data << " ";
            head = head->next;
        }
    }
    else {
        std::cout << "The list is empty!";
    }
}

void print_list_reverse(Node* head) {

    if(head != nullptr) {

        print_list_reverse(head->next);
        std::cout << head->data << " ";
    }
    else {
        std::cout << "The list is empty!";
    }
}

void add_first(Node* &head, int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void add_last(Node* &head, int data) {

    if(head != nullptr) {
        
        Node* temp = head;
        while(temp->next != nullptr) {

            temp = temp->next;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        temp->next = newNode;    
    }
    else {
        add_first(head,data);
    }
}

void add_after(Node* prev, int data) {

    if(prev != nullptr) {

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void add_pos(Node* &head, int data, int pos) {

    if(pos == 0) {
        if(size(head) == 0) {
            add_last(head,data);
        }
        else if (size(head) == 1) {
            add_first(head,data);
        }
    }

    if(check_pos(size(head),pos) ) {

        if(pos > 0 && pos <= size(head)-1) {

            Node* temp = head;
            int currentPos = 0;
            while(currentPos != pos-1) {

                temp = temp->next;
                ++currentPos;
            }

            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void update_pos(Node* &head, int data, int pos) {

    if(head != nullptr && check_pos(size(head),pos) ) {

        if(pos == 0) {
            head->data = data;
        }
        else {

            Node* temp = head;
            int currentPos = 0;
            while(currentPos != pos) {

                temp = temp->next;
                ++currentPos;
            }

            temp->data = data;
        }
    }
}

void remove_first(Node* &head) {

    if(head != nullptr) {

        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void remove_last(Node* &head) {

    if(head != nullptr) {

        if(head->next == nullptr)
            head = nullptr;
        else {

            Node* temp = head;
            while(temp->next->next != nullptr) {
                
                temp = temp->next;
            }

            Node* lastNode = temp->next;
            temp->next = nullptr;
            delete lastNode;
        }
    }
}

void remove_pos(Node* &head, int pos) {

    if(head != nullptr && check_pos(size(head),pos) ) {

        if(pos == 0) {
            remove_first(head);
        }
        else if(pos == size(head)-1) {
            remove_last(head);
        }
        else if(pos > 0 && pos < size(head)-1) {

            int currentPos = 0;
            Node* prev = head;
            while(currentPos != pos-1) {

                prev = prev->next;
                ++currentPos;
            }

            Node* temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
        }
    }
}

bool check_pos(int listSize, int pos) {

    if(pos >= 0 && pos <= listSize-1) {
        return true;
    }

    return false;
}

bool check_pos(int listSize, int start, int end) {

    if(start <= end && 
    start >= 0 && start <= listSize-1 && 
    end >= 0 && end <= listSize-1) {
        return true;
    }

    return false;
}

void remove_sublist(Node* &head, int start, int end) {

    if(head != nullptr && check_pos(size(head), start, end) ) {

        if(start == 0 && end == size(head)-1) {
            delete_list(head);
        }
        else if(start == end) {
            remove_pos(head,start);
        }
        else {
             
            while(start <= end) {

                remove_pos(head,start);
                --end;      // the end must shrink, the start is the index that must stay the same
            }
        }
    }
}

void delete_list(Node* &head) {

    Node* temp = head;
    Node* next = nullptr;
    while(temp != nullptr) {

        next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

bool exist(Node* head, int data) {

    if(head == nullptr) {
        return false;
    }
    
    Node* temp = head;
    while(temp != nullptr) {
        
        if(temp->data == data) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

Node* reverse_list(Node* &head) {

    if(head == nullptr) {
        return nullptr;
    }

    Node* prev = nullptr;
    Node* temp = head;

    while(temp != nullptr) {
        
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    Node* newHead = prev;
    return newHead;         // returns the reversed list
}

Node* reverse_list_recur(Node* &head) {

    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = reverse_list_recur(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

Node* rotate_list(Node* &head, int shift) {

    if(head == nullptr) {
        return nullptr;
    }

    int size = 0;
    Node* tail = head;
    while(tail->next != nullptr) {
        ++size;
        tail = tail->next;
    }
    size++;     // including the last node

    shift = shift%size;
    
    if(shift == 0) {
        return head;
    }

    tail->next = head;
    Node* temp = head;
    for(int i = 1; i < size-shift; ++i) {
        temp = temp->next;
    }
    // temp is now pointing to (size-shift)th node
    
    Node* newHead = temp->next;
    temp->next = nullptr;
    return newHead;
}

bool equal(Node* head1, Node* head2) {

    if(head1 == nullptr && head2 == nullptr) {
        return true;
    }

    if((head1 == nullptr && head2 != nullptr) || (head1 != nullptr && head2 == nullptr)) {
        return false;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != nullptr && temp2 != nullptr) {

        if(temp1->data != temp2->data){
            return false;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // either temp1 is null, or temp2 is null, or both are null
    return (temp1 == nullptr && temp2 == nullptr);
}

void cut_edges(Node* &head) {

    if(head != nullptr) {

        remove_first(head);
        remove_last(head);
    }
}

bool is_palindrome(Node* head) {

    /*
    Node* temp1 = head;
    Node* temp2 = reverse_list(head);
    return equal(temp1,temp2);
    */
    
    if(head == nullptr) {
        return true;
    }

    Node* firstHalf = head;
    Node* secondHalf = head;

    while(secondHalf != nullptr && secondHalf->next != nullptr) {

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next->next;
    }

    // break the list in the middle
    Node* temp = firstHalf->next;
    Node* prev = firstHalf;
    firstHalf->next = nullptr;

    // reverse second half of the list
    while(temp) {
        
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    Node* head1 = head;
    Node* head2 = prev;
    
    while(head2) {

        if(head1->data != head2->data) {
            return false;
        }
        
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

bool is_empty(Node* head) {

    if(head == nullptr) {
        return true;
    }
    
    return false;
}

int size (Node* head) {

    if(is_empty(head)) {
        return 0;
    }
    
    Node* temp = head;
    int currentPos = 0;
    while(temp != nullptr) {

        temp = temp->next;
        ++currentPos;
    }

    return currentPos;
}

int count_value(Node* head,int data) {

    if(is_empty(head)) {
        return 0;
    }
    
    Node* temp = head;
    int count_value = 0;
    while(temp != nullptr) {
        
        if(temp->data == data) {
            ++count_value;
        }
        
        temp = temp->next;
    }

    return count_value;
}

Node* extract_first(Node* head) {

    if(head != nullptr) {
        
        Node* newNode = new Node();
        newNode->data = head->data;
        newNode->next = nullptr;

        return newNode;
    }
    
    return nullptr;
}

Node* extract_last(Node* head) {

    if(head != nullptr) {
        
        Node* newNode = new Node();
        Node* temp = head;
        while(temp->next != nullptr) {

            temp = temp->next;
        }
        newNode->data = temp->data;
        newNode->next = nullptr;

        return newNode;
    }
    
    return nullptr;
    /*
    head = reverse_list(head);
    Node* temp = head;
    head = reverse_list(head);
    return temp; 
    */
}

Node* get_first(Node* head) {

    if(head != nullptr) {
        
        return head;
    }
    
    return nullptr;
}

Node* get_last(Node* head) {

    if(head != nullptr) {
        
        Node* temp = head;
        while(temp->next != nullptr) {

            temp = temp->next;
        }

        return temp;
    }
    
    return nullptr;
}

Node* get_node_pos(Node* head, int pos) {

    if(head != nullptr && check_pos(size(head),pos) ) {

        if(pos == 0) {
            return head;   
        }
        else if(pos > 0 && pos <= size(head)-1) {

            int currentPos = 0;
            Node* temp = head;
            while(currentPos != pos-1) {

                temp = temp->next;
                ++currentPos;
            }

            return temp->next;  // the node at the right pos is temp->next
        }   
    }    

    return nullptr;
}

Node* get_node_value(Node* head, int data) {

    if(head != nullptr && exist(head,data)) {

        Node* temp = head;
        while(temp != nullptr && temp->data != data) {

            temp = temp->next;
        }

        return temp;
    }

    return nullptr;
}

Node* extract_pos(Node* head, int pos) {

    if(head != nullptr && check_pos(size(head),pos) ) {

        if(pos == 0) {
            Node* newNode = new Node();
            newNode->data = head->data;
            newNode->next = nullptr;
            return newNode;   
        }
        else if(pos > 0 && pos <= size(head)-1) {

            int currentPos = 0;
            Node* newNode = new Node();
            Node* temp = head;
            while(currentPos != pos-1) {

                temp = temp->next;
                ++currentPos;
            }

            newNode->data = temp->next->data;     // the node at the right pos is temp->next
            newNode->next = nullptr;
            return newNode;
        }    
    }
    
    return nullptr;
}

Node* extract_sublist(Node* head, int start, int end) {
    
    if(head != nullptr  && check_pos(size(head), start, end)) {

        if(start == end) {
            return extract_pos(head,start);
        }

        if(start == 0 && end == size(head)-1) {
            
            Node* newList = nullptr;
            Node* temp = head;
            while(start <= size(head)-1) {
                
                int data = temp->data;
                add_last(newList,data);
                temp = temp->next;
                ++start;
            }
            
            return newList;
        }

        Node* temp = head;
        int currentPos = 0;
        while(currentPos != start) {
            temp = temp->next;
            ++currentPos;
        }

        Node* newList = nullptr;
        while(start <= end) {
            
            int data = temp->data;
            add_last(newList,data);
            temp = temp->next;
            ++start;
        }
            
        return newList;
    }
    
   return nullptr;
}

Node* concat_self_list(Node* head) {

    if(head == nullptr) {
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }

    Node* temp = head;
    int sizeBeforeConcat = size(head);
    for(int i = 0; i < sizeBeforeConcat; ++i) {

        add_last(tail->next,temp->data);
        tail = tail->next;
        temp = temp->next;
    }
    
    return head;
}

Node* concat_list(Node* head1, Node* head2) {

    if(head1 == nullptr) {
        
        Node* newList = nullptr;
        Node* temp = head2;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }
    
    if(head2 == nullptr) {
        
        Node* newList = nullptr;
        Node* temp = head1;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }

    // this avoid getting in an infinite loop if we are concatenating the same list
    if(head1 != head2 || !equal(head1,head2)) {
        
        Node* newList = nullptr;
        Node* tail1 = head1;
        while(tail1->next != nullptr) {
            
            add_last(newList,tail1->data);
            tail1 = tail1->next;
        }

        Node* tail2 = head2;
        while(tail2->next != nullptr) {
            
            add_last(newList,tail2->data);
            tail2 = tail2->next;
        }

        return newList;
    }
    
    return nullptr;
}

Node* merge_list(Node* head1, Node* head2) {

    if(head1 == head2 || equal(head1,head2)) {
        
        // because just returning head1 will grant at the newList the access at the same list as head1
        // basically just having two pointers to the same list
        Node* newList = nullptr;
        Node* temp = head1;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }

    if(head1 == nullptr) {

        Node* newList = nullptr;
        Node* temp = head2;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }

    if(head2 == nullptr) {
        
        Node* newList = nullptr;
        Node* temp = head1;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* newList = nullptr;

    while(temp1 != nullptr) {
        
        if(!exist(newList,temp1->data)) {
            add_last(newList,temp1->data);
        }

        temp1 = temp1->next;
    }

    while(temp2 != nullptr) {

        if(!exist(newList,temp2->data)) {
            add_last(newList,temp2->data);
        }

        temp2 = temp2->next;
    }

    return newList;
}

Node* intersect_list(Node* head1, Node* head2) {

    if(head1 == head2 || equal(head1,head2)) {
        
        Node* newList = nullptr;
        Node* temp = head1;
        while(temp != nullptr) {

            add_last(newList,temp->data);
            temp = temp->next;
        }

        return newList;
    }

    if(head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* newList = nullptr;

    while(temp1 != nullptr) {

        temp2 = head2;
        while(temp2 != nullptr) {

            if(temp1->data == temp2->data && !exist(newList,temp1->data)) {
                add_last(newList,temp1->data);
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return newList;
}

int min(Node* head) {

    if(head == nullptr) {
        return 0;
    }

    int min = head->data;
    Node* temp = head;
    while(temp != nullptr) {

        if(temp->data < min) {
            min = temp->data;
        }

        temp = temp->next;
    }

    return min;
}

int max(Node* head) {
    
    if(head == nullptr) {
        return 0;
    }
    
    int max = head->data;
    Node* temp = head;
    while(temp != nullptr) {

        if(temp->data > max) {
            max = temp->data;
        }

        temp = temp->next;
    }

    return max;
}