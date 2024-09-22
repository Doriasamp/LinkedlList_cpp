#include "Node.h"

int main(){
    std::cout << "TEST EMPTY NODE W/O VALUE AND NEXT" << std::endl;
    Node empty_node = Node();     // creating an instance of a Node without initialization, it should use the default parameters in contructor.
    empty_node.display_node();

    std::cout << "\nTEST NODE WITH VALUE AND W/O NEXT" << std::endl;
    Node init_node = Node(1);   // creating an instance of a Node without partial initialization, it should use the 2nd default parameters in contructor.
    init_node.display_node();

    std::cout << "\nCREATE 2 NODES AND INITIALIZE THE SECOND ONE WITH FIRST NODE AS NEXT" << std::endl;
    Node* node1 = new Node(1);  // create a pointer called node in the stack, and create in the heap an instance of a Node initialized with a value
    Node *node2 = new Node(2, node1);
    node2->display_node();

    std::cout << "\nDESTROYING <NODE> INSTANCE IN THE HEAP WHERE node1 POINTER IS POINTING TO" << std::endl;
    // Destroying the Node object in the heap where node1 pointer is pointing to
    delete node1;
    node2->set_next(nullptr);
    node2->display_node();


    



    return 0;
}