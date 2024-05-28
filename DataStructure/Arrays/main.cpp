#include <iostream>

int main(){
    int values[10] = {2, 3, 5, 7, 11, 13, 15, 17, 21, 23};
    std::cout << "The size of the array:" << sizeof(values) << std::endl;
    int offset = (long)&values[2] - (long)&values[0];
    std::cout << "The length between the first and third" << offset << " vs expected: 2*4 = 8 bytes" << std::endl;
    std::cout << (long)&values[0] << std::endl;
    return 0;
}