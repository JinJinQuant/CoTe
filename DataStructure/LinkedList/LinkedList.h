#pragma once

template <typename T>
class LinkedList {
private:
    class ListNode {
    public:
        T data;  // Remove const to allow modification
        ListNode* next;
        ListNode(const T& data) : data(data), next(nullptr) { }
    };

    ListNode* head_;  // Pointer to the head of the list
    ListNode* _find(const T& data);

public:
    LinkedList() : head_(nullptr) { }  // Constructor to initialize head_
    ~LinkedList();  // Destructor declaration

    const T &operator[](unsigned index);  // Operator [] declaration, should be const
    void insert(const T& data, unsigned index = 0);
    void remove(unsigned index);
    void display() const;
};

// Include the implementation file
#include "LinkedList.hpp"