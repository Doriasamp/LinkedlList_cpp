#pragma once
#include "Node.h"
#include <string>

class LinkedList{
public:
    LinkedList(Node* init_node = nullptr);  // constructor
    LinkedList(const LinkedList& other);    // deep copy constructor
    ~LinkedList();
    LinkedList& operator=(const LinkedList& other); //overloaded assignment operator

    inline int get_head() const {return get_head_node_()->get_value();}
    inline int get_tail() const {return get_tail_node_()->get_value();}


    /**
     * @brief Insert elements in the LL in front.
     * 
     * @param value The element to insert.
     */
    void prepend(int);

    /**
     * @brief Insert element in the LL at the end.
     * 
     * @param value The element to insert.
     */
    void append(int);
    
    bool is_empty() const;

    /**
    * @brief Display in the console all the elements in the LL.
    */
    void print();

    /**
    * @brief Search if the value passed exists in the linkedlist.
    *
    * @param value The value to search for.
    * @return The index at which the value is stored in the LL, if the value is not present returns -1.
    */
    int search(int);





private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    inline Node* get_head_node_() const{return head_;}
    inline Node* get_tail_node_() const{return tail_;}
    void set_head_node_(Node*);
    void set_tail_node_(Node*);
    std::string recursive_print_(Node*, std::string);

};