### reference (&)

1. Reference in Variables

2. Reference in Function Arguments

3. Difference with Pointers


### const
This keyword is used to define constant variables, making them immutable after their initial assignment.
It helps to prevent unintentional changes in variables, enhancing code safety and stability.

```
// 1. constant variables
const int x = 10;
x = 20 -> generate error

// 2. Pointers and `const`
const int* p1 = &x;  // Pointer to a constant integer, the value pointed to cannot be changed
int* const p2 = &x;  // Constant pointer to an integer, the pointer itself cannot be changed
const int* const p3 = &x;  // Constant pointer to a constant integer, neither the pointer nor the value can be changed

// 3. Function Parameters
void myfunction(const int& value){
    value = 10; -> generate error // prevents the function form modifying passed arguments
}
```

### Template
A template type is a special type that can take on different types when the type is initialized.

Template genralizes a data type when we make a function of a class, it allows that those can fuction accross various data types with out relying on a particular type.

```
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (elements.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        elements.pop_back();
    }

    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;        // int 타입 스택
    Stack<std::string> stringStack;  // string 타입 스택

    intStack.push(1);
    intStack.push(2);
    std::cout << "Top of intStack: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Top of intStack after pop: " << intStack.top() << std::endl;

    stringStack.push("hello");
    stringStack.push("world");
    std::cout << "Top of stringStack: " << stringStack.top() << std::endl;
    stringStack.pop();
    std::cout << "Top of stringStack after pop: " << stringStack.top() << std::endl;

    return 0;
}
```

i.e.) vector (vector<char>, vector<int>, vector<myClass::Class>, ...)

