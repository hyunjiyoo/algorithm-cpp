#include <iostream>

int main (int argc, const char * argv []) {

    int iarr[10];

    // before memset
    for (int i = 0; i < 10; ++i)
        std::cout << iarr[i] << " ";
    std::cout << std::endl;

    int* addr = (int*)((long long int)(&iarr[0]) + 3);

    std::memset(addr, 0x02, 5);

    // after memset
    for (int i = 0; i < 10; ++i)
        std::cout << iarr[i] << " ";
    std::cout << std::endl;

    

//    float farr[10];
//    std::memset(farr, 1.0, 5);
//    for (int i = 0; i < 10; ++i)
//        std::cout << farr[i] << " ";
//    std::cout << std::endl;
//
//    float test;
//    int* ptr = (int*)&test;
//    *ptr = 0x01010101;
//    std::cout << sizeof test << test;
//    std::cout << std::endl;
    
    
    return 0;
}

