//
//  combinationOf6.cpp
//  algorithm
//
//  Created by USER on 2021/03/03.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    const int size = 6;
    bool check[size];
    for(int i = 0; i < size; ++i) {
        check[i]= false;
    }
    
    int numList[size-2];
    int idx = 0;
    
    for(int i = 0; i < 1; ++i) {
        check[i] = true;
        
        for(int j = i + 1; j < size; ++j) {
            check[j] = true;
    
            idx = 0;
            
            for(int k = 0; k < size; ++k) {
                if(check[k] == false) {
                    numList[idx++] = k;
                }
            }
            
            for(int m = 0; m < idx; ++m) {
                check[numList[m]] = true;
                
                for(int n = m + 1; n < idx; ++n) {
                    check[numList[n]] = true;
                    std::cout << i << ' ' << j << ' ' << numList[m] << ' ' << numList[n] << ' ';
                    
                    for(int p = 0; p < size; ++p) {
                        if(check[p] == false) {
                            std::cout << p << ' ';
                        }
                    }
                    std::cout << std::endl;
                    check[numList[n]] = false;
                }
                check[numList[m]] = false;
            }
            check[j] = false;
        }
        check[i] = false;
    }
 
    return 0;
}
