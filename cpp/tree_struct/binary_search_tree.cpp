#include <iostream>
#include <queue>
#include "binary_search_tree.hpp"


void insert(Node* &root, int data) {

    // this implementation of a BST tree can not have duplicate nodes
    if(exist(root,data))
        return;

    if(root == nullptr) {
        
        root = new Node();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        
        if(data < root->data) {
            insert(root->left,data);
        }
        else {
            insert(root->right,data);
        }
    }
}

// should be used carefully because does not check if the 
// tree is still a BST
void update(Node* &root, int data, int newData) {

    if(root != nullptr && exist(root,data)) {

        if(root->data == data) {
            root->data = newData;
        }
        else {
            update(root->left,data,newData);
            update(root->right,data,newData);
        }
    }
}

Node* min_node(Node* root) {
    
    if(root == nullptr)
        return nullptr;

    while(root->right != nullptr) {
        
        root = root->right;
    }

    return root;
}

Node* predecessor(Node* root) {
    
    if(root == nullptr)
        return nullptr;
    
    root = root->left;
    while(root->right != nullptr) {

        root = root->right;
    }
    
    return root;
}

Node* max_node(Node* root) {
    
    if(root == nullptr)
        return nullptr;

    while(root->left != nullptr) {
        
        root = root->left;
    }

    return root;
}

Node* successor(Node* root) {
    
    if(root == nullptr)
        return nullptr;
    
    root = root->right;
    while(root->left != nullptr) {

        root = root->left;
    }
    
    return root;
}

void delete_tree(Node* &root) {

    if(root != nullptr) {
        
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = nullptr;
    }
}

Node* delete_node(Node *root, int data) {
    
    if(root == nullptr || !exist(root,data)) {
        return nullptr;
    }
    else if(data < root->data) {
        root->left = delete_node(root->left,data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right,data);
    }
    else {
        // case 1 - no child
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        // case 2 - one child
        else if(root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        // case 2 - one child
        else if(root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3 - 2 children
        else {
            
            Node *temp = max_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }

    return root;  
}

void print_in_order(Node* root) {

    if(root != nullptr) {
        
        if(root->left != nullptr)
            print_in_order(root->left);
        
        std::cout << root->data << " ";
        
        if(root->right != nullptr)
            print_in_order(root->right);
    }
    else {
        std::cout << "The BST is empty!";
    }
}

void print_pre_order(Node* root) {

    if(root != nullptr) {
        
        std::cout << root->data << " ";
        
        if(root->left != nullptr)
            print_in_order(root->left);
        
        if(root->right != nullptr)
            print_in_order(root->right);
    }
    else {
        std::cout << "The BST is empty!";
    }
}

void print_post_order(Node* root) {

    if(root != nullptr) {
        
        if(root->left != nullptr)
            print_in_order(root->left);
        
        if(root->right != nullptr)
            print_in_order(root->right);
        
        std::cout << root->data << " ";
    }
    else {
        std::cout << "The BST is empty!";
    }
}

void print_bfs(Node* root) {

    if(root == nullptr) {
        std::cout << "The BST is empty!";
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while(q.size() > 0) {

        int level = q.size();
        while(level > 0) {

            Node* temp = q.front();
            q.pop();
            std::cout << " " << temp->data;

            if(temp->left != nullptr) {
                q.push(temp->left);
            }
            if(temp->right != nullptr) {
                q.push(temp->right);
            }
            level--;
        }
        std::cout << "\n";
    }
}

int count_leaves(Node* root) {

    if(root == nullptr) {
        return 0;
    }
    else if(root->left == nullptr && root->right == nullptr){
        return 1;
    }
    else {
        int count_left = count_leaves(root->left);
        int count_right = count_leaves(root->right);
        return count_left + count_right;
    }
}

int count_nodes(Node* root) {

    if(root == nullptr) {
        return 0;
    }
    else {
        int count_left = count_nodes(root->left);
        int count_right = count_nodes(root->right);
        return count_left + count_right + 1;
    }
}

int height(Node* root) {

    if(root == nullptr) {
        return 0;
    }
    else {
        int count_left = height(root->left);
        int count_right = height(root->right);
        int max = std::max(count_left, count_right);
        return max + 1;
    }
}

int count_left_nodes(Node* root) {

    if(root == nullptr) {
        return 0;
    }
    else {
        int count_left = count_left_nodes(root->left);
        int count_right = count_left_nodes(root->right);
        int c = 0;
        if(root->left != nullptr) {
            c = 1;
        }
        else {
            c = 0;
        }
        
        return count_left + count_right + c;
    }
}

int count_right_nodes(Node* root) {

    if(root == nullptr) {
        return 0;
    }
    else {

        int count_left = count_right_nodes(root->left);
        int count_right = count_right_nodes(root->right);
        int c = 0;
        if(root->right != nullptr) {
            c = 1;
        }
        else {
            c = 0;
        }
        
        return count_left + count_right + c;
    }
}

Node* search(Node* root, int data) {

    if(root == nullptr || !exist(root,data)) {
        return nullptr;
    }

    if(root->data == data) {

        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* newNode = new Node();
    if(root->data > data) {
        Node* newNode = search(root->left,data);
    }
    else {
        Node* newNode = search(root->right,data);
    }

    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool exist(Node* root, int data) {

    if(root == nullptr) {
        return false;
    }

    if(root->data == data) {
        return true;
    }
    else if(data < root->data) {
        return exist(root->left,data);
    }
    else if(data > root->data){
        return exist(root->right,data);
    }
    else {  // if data != root->data (because in this BST all the nodes have unique values)
        return false;
    }
}

bool is_empty(Node* root) {

    if(root == nullptr) {
        return true;
    }

    return false;
}

bool equal(Node* root1, Node* root2) {

    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if((count_nodes(root1) != count_nodes(root2)) || height(root1) != height(root2)) {
        return false;
    }

    if(root1 == nullptr && root2 != nullptr) {
        return false;
    }

    if(root1 != nullptr && root2 == nullptr) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }
    else {
        return equal(root1->left,root2->left) && equal(root1->right,root2->right);
    }

}

bool bst_checker(Node* root, int min, int max) {

    if(root == nullptr) {
        return true;
    }

    if(root->data < min || root->data > max) {
        return false;
    }

    return bst_checker(root->left, min, root->data - 1) &&
    bst_checker(root->right, root->data + 1, max);
}

bool is_bst(Node* root) {

    return bst_checker(root, INT_MIN, INT_MAX);
}