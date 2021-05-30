#include <iostream>

struct student {
    int id;
    char name[12];
};

void test(int* arr) {
    std::cout << sizeof arr << std::endl;
}

void test2(int (&arr)[100]) {
    std::cout << sizeof arr << std::endl;
}

int main (int argc, const char * argv []) {
    // pass arr to function
    {
        int arr[100];
        std::cout << sizeof arr << std::endl;
        
        test(arr);
        
        test2(arr);
        
        std::cout << std::endl;
        
    }
    
    // float arr test
    {
        float arr[10];
        std::memset(arr, 1.0, 5);
        for (int i = 0; i < 10; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        
        float test;
        int* ptr = (int*)&test;
        *ptr = 0x01010101;
        std::cout << sizeof test << test;
        std::cout << std::endl;
    }
    
    
    // int arr test
    {
        int arr[10];
        
        // before memset
        for (int i = 0; i < 10; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        int* addr = (int*)((long long int)(&arr[0]) + 3);
        
        std::memset(addr, 0x02, 5);
        
        // after memset
        for (int i = 0; i < 10; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
    
    
    // struct test
    {
        student std;
        
        std::memset(&std, 0xFF, 10);
        
        std::cout << std.name << std::endl;
        
        for (int i = 0; i < 12; ++i) {
            std::cout << (int)(std.name[i]) << " ";
        }
        std::cout << std::endl;
        
        std::cout << sizeof std << std::endl;
    }
    
    return 0;
}

