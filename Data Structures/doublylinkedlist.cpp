#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * prev;
    node * next;
};

void push_after(node * nd, int element){
    node * new_node = new node();
    new_node->data = element;
    new_node->next = nd->next;
    nd->next = new_node;
    new_node->prev = nd;
    if(new_node->next) (new_node->next)->prev = new_node;
}

void print_list(node * head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    node * head = new node();
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;
    push_after(head, 2);
    push_after(head, 3);
    print_list(head);
    node * last = head;
    node * it = head->next;
    while(it){
        last = it;
        it = it->next;
    }
    while(last){
        cout << last->data << " ";
        last = last->prev;
    }
    cout << "\n";
    return 0;
}