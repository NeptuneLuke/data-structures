#ifndef linked_list_struct
#define linked_list_struct

struct Node {

    int data;
    Node* next;
};

void print_list(Node* head);
void print_list_reverse(Node* head);

void add_first(Node* &head, int data);                  // add a new node at the head
void add_last(Node* &head, int data);                   // add a new node at the end
void add_after(Node* previousNode, int data);
void add_pos(Node* &head, int data, int pos);           // add a new node at pos
void update_pos(Node* &head, int data, int pos);        // update the node at pos with value data

void remove_first(Node* &head);
void remove_last(Node* &head);
void remove_pos(Node* &head, int pos);                  // remove the node at pos
void remove_sublist(Node* &head, int start, int end);   // remove all the nodes between [start,end]
void delete_list(Node* &head);                          // delete every node of the list
void cut_edges(Node* &head);                            // remove the first and last node

Node* reverse_list(Node* &head);
Node* reverse_list_recur(Node* &head);
Node* rotate_list(Node* &head, int shift);          // rotates the list right by shift times
Node* concat_self_list(Node* head);                 // returns the concatenation of head+head
Node* concat_list(Node* head, Node* head2);         // returns the concatenation of head+head2
Node* intersect_list(Node* head1, Node* head2);     // pick the nodes present in both lists one time
Node* merge_list(Node* head1, Node* head2);         // pick all the nodes present in the lists one time

Node* get_node_first(Node* head);                           // returns the first node itself(reference)
Node* get_node_last(Node* head);                            // returns the last node itself(reference)
Node* get_node_pos(Node* head, int pos);                    // returns the node itself(reference) at pos
Node* get_node_value(Node* head, int data);                 // returns the first occurence of the node itself(reference) with value data
Node* extract_first(Node* head);                            // extract a "copy"(new node with the same data as) the first node
Node* extract_last(Node* head);                             // extract a "copy"(new node with the same data as) the last node
Node* extract_pos(Node* head, int pos);                     // extract a "copy" of the node at pos
Node* extract_sublist(Node* head, int start, int end);      // extract a "copy" of the sublist between [start, end]

bool check_pos(int listSize, int pos);              // check if the pos is between bounds
bool check_pos(int listSize, int start, int end);   // check if start and end are between bounds

bool is_empty(Node* head);
int size (Node* head);
bool exist(Node* head, int data);                   // check if there is a node with value data in the list
bool equal(Node* head1, Node* head2);               // check if two lists are the same (same data in the same order)
bool is_palindrome(Node* head);
int count_value(Node* head,int data);              // returns the number of times the value data is in the list
int min(Node* head);
int max(Node* head);

#endif