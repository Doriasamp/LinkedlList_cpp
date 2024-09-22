#pragma once
# include <iostream>

class Node{
public:
    Node(int value = 0, Node* next = nullptr);
    ~Node();
    void set_value(int);
    void set_next(Node*);
    int get_value() const;
    Node* get_next() const;
    
    void display_node();

private:
    int value_;
    Node* next_ = nullptr;
    
};