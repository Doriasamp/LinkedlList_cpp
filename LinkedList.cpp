#include "LinkedList.h"

LinkedList::LinkedList(Node* init_node):head_{init_node}, tail_{init_node}
{

}

LinkedList::LinkedList(const LinkedList& other) // deep copy constructor by traversing the LL
{
    if(other.is_empty())
        return;

    Node* temp_head = other.get_head_node_();
    while(temp_head){
        this->append(temp_head->get_value());
        temp_head = temp_head->get_next();
    }

}

LinkedList& LinkedList::operator=(const LinkedList& source)
{
    return *this;

}

LinkedList::~LinkedList()
{
    if (head_)
        delete head_;
    head_ = nullptr;

}

void LinkedList::prepend(int value){
    Node* new_node = new Node(value);
    if (!head_){
        head_ = new_node;
        tail_ = new_node;
    }
    else{
        new_node->set_next(head_);
        head_ = new_node;
    }
}

void LinkedList::append(int value){
    Node* new_node = new Node(value);
    if (!head_){
        head_ = new_node;
        tail_ = new_node;
    }
    else{
        tail_->set_next(new_node);
        tail_ = new_node;
    }
}

bool LinkedList::is_empty() const{
    if(!head_)
        return true;
    return false;
}


void LinkedList::print(){
    std::string string = "";
    if (!head_){
        std::cout << "Empty linked list" << std::endl;
    }
    else{
        std::string string = std::to_string(head_->get_value()) + " -> ";
        string = recursive_print_(head_, string);
        std::cout << string << std::endl;
    }
}


int LinkedList::search(int value) const{
    Node* head = head_;
    int index = 0;
    while(head){
        if(head->get_value() == value)
            return index;
        else
            head = head->get_next();
            index++;
    }
    return -1;
}

bool LinkedList::delete_first(int value) {
    if (is_empty())
        return false;
    else if (head_->get_value() == value)   // first value to delete is the head value
    {
        Node* temp_head = head_;
        head_ = head_->get_next();
        temp_head->set_next(nullptr);
        delete temp_head;
        return true;
    }
    else
        return recursive_delete_(head_, value);
    return false;
}

// PRIVATE METHODS

std::string LinkedList::recursive_print_(Node* head, std::string string){
    if (!head->get_next()){
        return string;
    }
    else{
        head = head->get_next();
        string += (std::to_string(head->get_value()) + " -> ");
        return recursive_print_(head, string);
    }
}

bool LinkedList::recursive_delete_(Node* head, const int value){
    if(!head->get_next())   // base case no value match at end of recursion stack
        return false;
    else if(head->get_next()->get_value() == value)  // base case value matched before LL end
    {
        Node* node_to_delete = head->get_next();
        if(node_to_delete->get_next()){
            head->set_next(node_to_delete->get_next());
        }
        else{
            head->set_next(nullptr);
            tail_ = head;  
        }
        node_to_delete->set_next(nullptr);
        delete node_to_delete;
        return true;
    }
    return recursive_delete_(head->get_next(), value);
}

