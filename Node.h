#ifndef NODE_H
#define NODE_H

template<class S> 
struct Node{
    Node* prev;
    Node* next;
    S data; 

    Node(S value){
        data = value;
        next = nullptr;
        prev = nullptr; 
    }

    bool operator==(const Node&other){
        return data == other.data; 
    }
};

#endif