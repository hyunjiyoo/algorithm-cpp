#include <iostream>

struct student {
    int id;
    char name[12];
};

int main (int argc, const char * argv []) {
    
    student std;
    
    std::memset(&std, 0xFF, 10);
    
    std::cout << std.name << std::endl;
    
    for (int i = 0; i < 12; ++i) {
        std::cout << (std.name[i]) << " ";
    }
    std::cout << std::endl;
    
    std::cout << sizeof std << std::endl;

    return 0;
}

