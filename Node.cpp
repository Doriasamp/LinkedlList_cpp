#include "Node.h"

Node::Node(int value, Node* next):value_{value}, next_{next}
{

}

Node::~Node()
{

}

void Node::set_value(int value){value_ = value;}
void Node::set_next(Node* next_node){next_ = next_node;}

int Node::get_value() const {return value_;}
Node* Node::get_next() const {return next_;}

void Node::display_node(){
    if (next_)
    {
        std::cout << "Node value: " << value_ << "; next node value: " << next_->get_value() <<std::endl;
    }
    else
    {
    std::cout << "Node value: " << value_ << "; next node is null pointer" << std::endl;
    }
}


