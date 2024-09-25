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

    int list_of_values[5] = {3,4,8,7,23};
    for (const int& i: list_of_values){
        LL.prepend(i);  // inserting all the elements of array in the LL at iteration
    }
    LL.print();

    std::cout << "\n LL head: " << LL.get_head() << "; LL tail: " << LL.get_tail() << std::endl;

    std::cout << "Searching for value '4' in the LL: " << LL.search(4) << std::endl;
    std::cout << "Searching for value '7' in the LL: " << LL.search(7) << std::endl;
    std::cout << "Searching for value '5' in the LL: " << LL.search(5) << std::endl;
    std::cout << "Searching for value '64' in the LL: " << LL.search(64) << std::endl;

    // test deep copy constructorf
    LinkedList new_LL = LL;
    std::cout << "\nResult of copy constructor ..." << std::endl;
    new_LL.print();

    // trivia test by copying an empty LL
    LinkedList empty_LL = LinkedList();
    LinkedList copy_empty_LL = empty_LL;
    std::cout << "\nResult of copy constructor with empty LL..." << std::endl;
    copy_empty_LL.print();

    // testing delete_first()
    LL.append(3);
    LL.append(5);
    LL.append(3);
    LL.prepend(3);
    std::cout << "\nPrintout of LL before deleting value: 3" << std::endl;
    LL.print();
    LL.delete_first(3);
    std::cout << "\nPrintout of LL after deleting value: 3" << std::endl;
    LL.print();
    LL.delete_first(3);
    std::cout << "\nPrintout of LL after deleting value: 3" << std::endl;
    LL.print();
    LL.delete_first(3);
    std::cout << "\nPrintout of LL after deleting value: 3" << std::endl;
    LL.print();
    LL.delete_first(3);
    std::cout << "\nPrintout of LL after deleting (LAST) value: 3" << std::endl;
    LL.print();
    std::cout << "Trying to delete the value 3 after deleting all of them: " << std::endl;
    std::cout << LL.delete_first(3) << std::endl;



    return 0;
}