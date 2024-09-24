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

LinkedList& LinkedList::operator=(const LinkedList& right)
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


int LinkedList::search(int value){
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