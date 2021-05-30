#include <iostream>

void test(int* arr) {
    std::cout << sizeof arr << std::endl;
}

void test2(int (&arr)[100]) {
    std::cout << sizeof arr << std::endl;
}

int main (int argc, const char * argv []) {
    
    int arr[100];
    
    std::cout << sizeof arr << std::endl;
    
    test(arr);
    test2(arr);
    
    std::cout << std::endl;
    
    return 0;
}

