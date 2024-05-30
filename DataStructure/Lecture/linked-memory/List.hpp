/**
 * Simple linked-memory, templated list class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

// Redundantly make sure theat List.h is included. Since List.h is written
// to include this file, we won't need to explicitly include List.hpp in
// the main.cpp file.
#include "List.h"

template <typename T>
const T & List<T>::operator[](unsigned index) {
  // Start a `thru` pointer to advance thru the list:
  ListNode *thru = head_;

  // Loop until the end of the list (or until a `nullptr`):
  while (index > 0 && thru->next != nullptr) {
    thru = thru->next;
    index--;
  }  

  // Return the data:
  return thru->data;
}


template <typename T>
void List<T>::insertAtFront(const T & data) {
  // Create a new ListNode on the heap:
  ListNode *node = new ListNode(data);

  // Set the new node’s next pointer point the current
  // head of the List:
  node->next = head_;

  // Set the List’s head pointer to be the new node:
  head_ = node;
}


/**
 * Finds and returns the ListNode containing `data` in the
 * List or `nullptr` if the data is not found.
 */
template <typename T>
typename List<T>::ListNode *List<T>::_find(const T & data) {
  ListNode *thru = head_;
  while (thru != nullptr) {
    if (thru->data == data) { return thru; }
    thru = thru->next;
  }

  return nullptr;  
}


// Find helper function
template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::_find(const T& data) {
    ListNode* current = head_;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }
    return current;
}

// Operator [] implementation
template <typename T>
const T& LinkedList<T>::operator[](unsigned index) {
    ListNode* current = head_;
    for (unsigned i = 0; i < index; ++i) {
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    return current->data;
}

// Insert function implementation
template <typename T>
void LinkedList<T>::insert(const T& value, unsigned index) {
    ListNode* newNode = new ListNode(value);

    if (index == 0) {
        newNode->next = head_;
        head_ = newNode;
        return;
    }

    ListNode* current = head_;
    for (unsigned i = 0; i < index - 1; ++i) {
        if (current == nullptr) {
            delete newNode;
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Remove function implementation
template <typename T>
void LinkedList<T>::remove(unsigned index) {
    if (head_ == nullptr) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        ListNode* toDelete = head_;
        head_ = head_->next;
        delete toDelete;
        return;
    }

    ListNode* current = head_;
    for (unsigned i = 0; i < index - 1; ++i) {
        if (current == nullptr || current->next == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }

    ListNode* toDelete = current->next;
    if (toDelete == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    current->next = toDelete->next;
    delete toDelete;
}

// Display function implementation
template <typename T>
void LinkedList<T>::display() const {
    ListNode* current = head_;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}