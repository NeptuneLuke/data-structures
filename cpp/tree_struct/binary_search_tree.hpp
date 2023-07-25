#ifndef binary_search_tree
#define binary_search_tree

// This implementation of a binary search tree
// can not have duplicate nodes
struct Node {

    int data;
    Node* left;
    Node* right;
};


void print_in_order(Node* root);
void print_pre_order(Node* root);
void print_post_order(Node* root);
void print_bfs(Node* root);                 // prints the BST tree in level order

void insert(Node* &root, int data);
void update(Node* &root, int data, int newData);        // update the node with value data with newData (should be used carefully!) 
Node* delete_node(Node* root, int data);                // delete the node with value data
void delete_tree(Node* &root);                          // delete the entire tree
Node* max_node(Node* root);                             // returns the maximum node of the tree/subtree (the node all the way to the right)
Node* min_node(Node* root);                             // returns the minimum node of the tree/subtree (the node all the way to the left)
Node* successor(Node* root);                            // returns the successor of the node root (the smallest node to the right of root)
Node* predecessor(Node* root);                          // returns the predecessor of the node root (the biggest node to the left of root)

int count_leaves(Node* root);               // counts the leaves of the tree
int count_nodes(Node* root);                // counts the nodes of the tree - function size() for data structures
int height(Node* root);                     // returns the height of the tree (deepest level starting from 1)
int count_left_nodes(Node* root);           // returns the numbers of left nodes 
int count_right_nodes(Node* root);          // returns the numbers of right nodes

Node* search(Node* root, int data);         // returns the node with the value data
bool exist(Node* root, int data);           // true if a node with value data exist, false otherwise
bool is_empty(Node* root);                  // true if the tree is null (so the size = 0), false otherwise
bool equal(Node* root1, Node* root2);       // true if root1 is equal to root2(contains the same nodes in the same order), false otherwise
bool is_bst(Node* root);                    // true if root is a BST, false otherwise
bool bst_checker(Node* root, int min, int max);     // the actual algorithm to check if the tree is BST or not

#endif