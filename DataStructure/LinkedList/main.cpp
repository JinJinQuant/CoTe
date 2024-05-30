#include "LinkedList.h"

int main(){
    LinkedList<int> linked_list;
    linked_list.insert(3);
    linked_list.display();

    linked_list.insert(5);
    linked_list.insert(7);
    linked_list.insert(213);
    linked_list.insert(210305);
    linked_list.insert(-523);
    linked_list.display();
    
    std::cout << linked_list[3] << std::endl;
    linked_list.remove(3);
    linked_list.display();
}