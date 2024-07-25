#include <bits/stdc++.h>
using namespace std;

template <class Type> class Node{
  public:
    Type data;
    Node<Type> * next;

    Node(Type val){
        this->data = val;
        this->next = NULL;
    }

    ~Node(){
        delete this->next;
        delete this;
    }
};

template <class Type> class LinkedList{
  private:
    int size;
    Node<Type> * head;
    Node<Type> * tail;

  public:
    LinkedList(){
        this->size = 0;
        this->head = this->tail = NULL;
    }

    ~LinkedList(){
        Node<Type> * it = this->head;
        while(it){
            Node<Type> * temp = it;
            it = it->next;
            delete temp;
        }
        delete this->head;
        delete this->tail;
        delete it;
        size = 0;
        delete this;
    }

    void push_back(Type element){
        this->size++;
        if(this->size == 1){
            this->head = new Node<Type>(element);
            this->tail = this->head;
        }
        else{
            Node<Type> * temp = new Node<Type>(element);
            this->tail->next = temp;
            this->tail = this->tail->next;
        }
    }
    
    void push_front(Type element){
        this->size++;
        if(this->size == 1){
            this->head = new Node<Type>(element);
            this->tail = this->head;
        }
        else{
            Node<Type> * temp = new Node<Type>(element);
            temp->next = this->head;
            this->head = temp;
        }
    }

    void insert_at(int position, Type element){
        if(position > this->size){
            cout << "Can't insert: Position out of bounds\n";
            return;
        }
        if(position == this->size){
            push_back(element);
            return;
        }
        if(position == 0){
            push_front(element);
            return;
        }
        this->size++;
        Node<Type> * it = this->head;
        position -= 1;
        while(position--){
            it = it->next;
        }
        Node<Type> * temp = new Node<Type>(element);
        temp->next = it->next;
        it->next = temp;
    }

    bool search(Type element){
        Node<Type> * it = this->head;
        while(it){
            if(it->data == element) return true;
            it = it->next;
        }
        return false;
    }

    void print(){
        Node<Type> * it = this->head;
        while(it){
            cout << it->data << " ";
            it = it->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList <int> lis;
    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    lis.push_front(0);
    lis.insert_at(4, 4);
    lis.print();
    cout << lis.search(5) << "\n";
    return 0;
}