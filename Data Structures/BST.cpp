#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * left, * right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinarySearchTree{
private:
    Node * root;
    void preorder(Node * root);
    void inorder(Node * root);
    void postorder(Node * root);
    Node * inorder_next(Node * root);
    Node * dell(Node * root, int data);

public:
    void insert(int data);
    void traverse();
    void inorder();
    void preorder();
    void postorder();
    Node * search(int data);
    void remove(int data);
};

void BinarySearchTree::preorder(Node * root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BinarySearchTree::inorder(Node * root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BinarySearchTree::postorder(Node * root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void BinarySearchTree::traverse(){
    preorder(this->root);
    cout << "\n";
    inorder(this->root);
    cout << "\n";
    postorder(this->root);
    cout << "\n";
}

void BinarySearchTree::preorder(){
    preorder(this->root);
    cout << "\n";
}

void BinarySearchTree::inorder(){
    inorder(this->root);
    cout << "\n";
}

void BinarySearchTree::postorder(){
    postorder(this->root);
    cout << "\n";
}

Node * BinarySearchTree::inorder_next(Node * node){
    if(node == NULL) return node;
    if(node->left == NULL and node->right == NULL) return node;
    if(node->left) return inorder_next(node->left);
    return node->right;
}

Node * BinarySearchTree::dell(Node * node, int data){
    if(node == NULL) return node;
    if(node->data > data) node->left = dell(node->left, data);
    else if(node->data < data) node->right = dell(node->right, data);
    else{
        if(node->left == NULL){
            Node * temp = node->right;
            // free(node);
            node = NULL;
            return temp;
        }
        else if(node->right == NULL){
            Node * temp = node->left;
            // free(node);
            node = NULL;
            return temp;
        }
        Node * temp = inorder_next(node->right);
        node->data = temp->data;
        node->right = dell(node->right, temp->data);
    }
    return node;
}

void BinarySearchTree::insert(int data){
    if(this->root == NULL) {
        this->root = new Node(data);
        return;
    }
    Node * it = this->root;
    while(it){
        if(data < it->data and it->left == NULL){
            it->left = new Node(data);
            return;
        }
        else if(data > it->data and it->right == NULL){
            it->right = new Node(data);
            return;
        }
        else if(data < it->data) it = it->left;
        else if(data > it->data) it = it->right;
        else if(data == it->data){
            cout << data << " Can't add same number\n";
            return;
        }
    }
}

Node * BinarySearchTree::search(int data){
    Node * it = this->root;
    while(it){
        if(data == it->data) return it;
        else if(data < it->data) it = it->left;
        else it = it->right;
    }
    return NULL;
}

void BinarySearchTree::remove(int data){
    this->root = dell(this->root, data);
}

int main(){
    BinarySearchTree bstt;
    bstt.insert(8);
    bstt.insert(3);
    bstt.insert(10);
    bstt.insert(1);
    bstt.insert(6);
    bstt.insert(14);
    bstt.insert(4);
    bstt.insert(7);
    bstt.inorder();
    // bstt->traverse();
    Node * found = bstt.search(7);
    if(found) cout << found->data << "\n";
    // else cout << "nope\n";
    // bstt->remove(6);
    // // bstt->traverse();
    // bstt->inorder();
    // found = bstt->search(7);
    // if(found) cout << found->data << "\n";
    // else cout << "nope\n";
    return 0;
}