//
//  10829.cpp
//  algorithm
//
//  Created by USER on 2021/03/03.
//

#include <iostream>

int bin[10];

void setArr() {
    for(int i = 0; i < 10; ++i) {
        bin[i] = 0;
    }
}

void setBinary(int num, int step = 0) {
    if(num == 1) {
        bin[step] = num % 2;
        return;
    }
    
    bin[step] = num % 2;
    num /= 2;
    step += 1;
    
    setBinary(num, step);
}

int main(int argc, const char * argv[]) {
    int num = 0;
    std::cin >> num;
    
    setArr();
    setBinary(num);
    
    int j = 0;
    for(int i = 10; i > 0; --i) {
        if(bin[i] == 1) {
            j = i;
            break;
        }
    }
    
    for(int i = j; i >= 0; --i) {
        std::cout << bin[i];
    }
    std::cout << std::endl;
    
    return 0;
}
