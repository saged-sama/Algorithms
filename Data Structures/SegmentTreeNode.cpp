#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    int start;
    int end;
    Node * left;
    Node * right;
    Node(int start, int end){
        this->start = start;
        this->end = end;
        this->left = NULL;
        this->right = NULL;
    }
};

class SegmentTree{
  private:
    Node * root;
    Node * buildTree(vector<int>& vec, int start, int end){
        Node * newNode = new Node(start, end);
        if(start == end){
            newNode->data = vec[start];
        }
        else{
            int mid = (start + end)/2;
            newNode->left = buildTree(vec, start, mid);
            newNode->right = buildTree(vec, mid+1, end);
            newNode->data = newNode->left->data + newNode->right->data;
        }
        return newNode;
    }
    void buildTree(vector<int>& vec, Node * node){
        if(node->start == node->end){
            node->data = vec[node->start];
        }
        else{
            buildTree(vec, node->left);
            buildTree(vec, node->right);
            node->data = node->left->data + node->right->data;
        }
    }
    void update(vector<int>& vec, Node * node, int indx, int v){
        if(node->start > indx or node->end < indx) return;
        if(node->start == indx and node->end == indx){
            vec[indx] += v;
            node->data = vec[indx];
            return;
        }
        update(vec, node->left, indx, v);
        update(vec, node->right, indx, v);
        node->data = node->left->data + node->right->data;
    }
    int QueryRange(Node * node, int i, int j){
        if(node->start > j or node->end < i) return 0;
        if(node->start >= i and node->end <= j){
            return node->data;
        }
        return QueryRange(node->left, i, j)+QueryRange(node->right, i, j);
    }
    void inorderPrint(Node * node){
        if(!node) return;
        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }
    void inorderReset(Node * node){
        if(!node) return;
        inorderReset(node->left);
        node->data = 0;
        inorderReset(node->right);
    }
  public:
    SegmentTree(vector<int>& vec){
        this->root = buildTree(vec, 0, vec.size()-1);
    }
    void buildTree(vector<int>&vec){
        buildTree(vec, this->root);
    }
    void update(vector<int>& vec, int indx, int v){
        update(vec, this->root, indx, v);
    }
    int QueryRange(int i, int j){
        return QueryRange(this->root, i, j);
    }
    void inorderPrint(){
        inorderPrint(this->root);
        cout << "\n";
    }
    void inorderReset(){
        inorderReset(this->root);
    }
};

int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        vector<int> v;
        string s; int q;
        cin >> s >> q;
        for(auto ch: s){
            v.push_back(ch-'0');
        }
        SegmentTree tree(v);
        cout << "Case " << t << ":\n";
        while(q--){
            char cmd; cin >> cmd;
            if(cmd == 'I'){
                int start, end;
                cin >> start >> end;
            }
        }
    }
    return 0;
}