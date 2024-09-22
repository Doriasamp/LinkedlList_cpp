#include "LinkedList.h"


int main(){
    LinkedList LL = LinkedList();  // create an empty LinkedList
    LL.print(); // print out of empty LL
    std::cout << "Is LL empty? " << LL.is_empty() << std::endl;

    LL.prepend(5);  // insert an element in front of the LL
    LL.print(); // printout
    std::cout << "Is LL empty? " << LL.is_empty() << std::endl;


    LL.prepend(12);  // insert a second element in the front
    LL.print();

    int list_of_values[4] = {3,4,8,7};
    for (const int& i: list_of_values){
        LL.prepend(i);  // inserting all the elements of array in the LL at iteration
    }
    LL.print();

    std::cout << "\n LL head: " << LL.get_head() << "; LL tail: " << LL.get_tail() << std::endl;

    std::cout << "Searching for value '4' in the LL: " << LL.search(4) << std::endl;
    std::cout << "Searching for value '7' in the LL: " << LL.search(7) << std::endl;
    std::cout << "Searching for value '5' in the LL: " << LL.search(5) << std::endl;
    std::cout << "Searching for value '64' in the LL: " << LL.search(64) << std::endl;



    return 0;
}