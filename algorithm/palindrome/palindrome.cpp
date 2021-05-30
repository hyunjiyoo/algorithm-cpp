#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int N;
std::vector<std::string> p;
int R[30];

void input() {
    std::cin >> N;
    std::string str;
    for (int i = 0; i < N; ++i) {
        std::cin >> str;
        p.push_back(str);
    }
    std::fill(R, R + 30, -1);
}


int solve(std::string s) {
    
    int ret = -1;
    
    int i = 0;
    int j = int(s.size()) - 1;
    bool change = false;

    while(i < j) {
        if (s[i] == s[j]) {
            ++i;
            --j;
            if ((std::abs(i - j) <= 1) && ret == -1)
                ret = 0;
        }
        
        else {
            
            if (!change) {
                    
                if (s[i + 1] == s[j]) {
                    ++i;
                    ret = 1;
                    change = true;
                }
                else if (s[i] == s[j - 1]) {
                    --j;
                    ret = 1;
                    change = true;
                }
                else {
                    ret = 2;
                    break;
                }
            }
            else {
                ret = 2;
                break;
            }
            
        }
    }
    
    i = 0;
    j = int(s.size()) - 1;
    change = false;
    
    if (ret == 2) {
        while(i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
                if ((std::abs(i - j) <= 1) && ret == -1)
                    ret = 0;
            }
            
            else {
                
                if (!change) {
                        
                    if (s[i] == s[j - 1]) {
                        --j;
                        ret = 1;
                        change = true;
                    }
                    else if (s[i + 1] == s[j]) {
                        ++i;
                        ret = 1;
                        change = true;
                    }
                    else {
                        ret = 2;
                        break;
                    }
                }
                else {
                    ret = 2;
                    break;
                }
                
            }
        }
    }
    
    return ret;
}


int main (int argc, const char * argv []) {
    input();
    
    for (int i = 0; i < p.size(); ++i)
        R[i] = solve(p[i]);

    for (int i = 0; i < p.size(); ++i)
        std::cout << R[i] << std::endl;

    
    return 0;
}
