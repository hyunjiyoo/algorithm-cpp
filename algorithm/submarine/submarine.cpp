#include <iostream>
#include <string>

std::string str;
std::string pat1 = "100*1#";
std::string pat2 = "01";

bool solve() {
    int i = 0;
    int j, k;
    bool chk;
    
    while (i < str.length()) {
        
        if (str[i] == '1') {
            j = 0;
            chk = false;
            while(j < pat1.length()) {
                if (str[i] == pat1[j]) {
                    ++i;
                    ++j;
                }
                else if (pat1[j] == '*') {
                    if (str[i] == '0')
                        ++i;
                    else
                        ++j;
                }
                else if (pat1[j] == '#') {
                    if (str[i] == '1') {
                        ++i;
                        chk = true;
                    }
                    else {
                        ++j;
                        if (str[i + 1] == '0' && chk) {
                            j = 1;
                            chk = false;
                        }
                    }
                }
                else {
                    return false;
                }
            }
            
        }
        else {
            k = 0;
            while(k < pat2.length()) {
                if (str[i] != pat2[k])
                    return false;
                
                ++i;
                ++k;
            }
        }
    }
   
    return true;
}


int main (int argc, const char* argv []) {
    
    std::cin >> str;
    
    if (solve())
        std::cout << "SUBMARINE";
    else
        std::cout << "NOISE";
    
    return 0;
}
