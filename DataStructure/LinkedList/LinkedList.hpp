/*
Header file: `List.h` - contains the class declaration, including member function declarations and any private members
Implementation File: `List.hpp` - This file is usually used for implementation of template functions or template classess
    Why we use .hpp file with .h file: To ensure that the complier build specific instances during the complie time. 
    In more simple terms, the complier should see the definition and the implementation of templates at the same time, 
    because templates is concretized during the complie time
*/
#include "LinkedList.h"

// destructor implementation
// walk through the list and delete (delete value and assign nullptr) all elements
template <typename T>
LinkedList<T>::~LinkedList() {
    ListNode* current = head_; 
    while(current != nullptr){
        ListNode* toDelete = current;
        current = current->next;
        delete toDelete;
        toDelete = nullptr;
    }
}

// find helper function
template<typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::_find(const T& data){
    ListNode* current = head_;
    while (current != nullptr && current->data != data){
        current = current->next;
    }
    return current; // if don't find the data, return nullptr (the last)
}

// indexing operator implementation
template <typename T>
const T& LinkedList<T>::operator[](unsigned index){
    ListNode* current = head_;
    while (index > 0 && current->next != nullptr){
        if (current == nullptr){
            throw std::out_of_range("Index out of range");
            current = current->next;
            index--;
        }
    }
    return current->data;
}

// insert function implementation
template <typename T>
void LinkedList<T>::insert(const T& data, unsigned index = 0){
    ListNode* new_node = new ListNode(data); // dynamically allocate for a new ListNode object

    // insert at the front
    if(index==0){
        new_node->next = head_;
        head_ = new_node; // updating the header pointer
        return;
    }

    // move to the i-1 th index
    ListNode* current = head_;
    for (unsigned i=0; i<index-1; ++i){
        if (current == nullptr){
            delete newNode;
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// remove function implementation
template <typename T>
void LinkedList<T>::remove(unsigned index = 0){
    if (head_ == nullptr){
        throw std::out_of_range("Index out of range");
    }

    if (index == 0){
        ListNode* toDelete = head_;
        head_ = head_->next;
        delete toDelete;
        toDelete = nullptr;
        return;
    }

    ListNode* current = head_;
    for(unsigned i=0; i<index-1; ++i){
        
    }
}