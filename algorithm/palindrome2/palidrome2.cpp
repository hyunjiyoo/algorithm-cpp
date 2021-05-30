#include <iostream>
#include <string>

int R;
std::string s;

void solve() {
    
    bool samechar = true;
    for (int i = 1; i < s.size(); ++i) {
        if (s[0] != s[i]) {
            samechar = false;
            break;
        }
    }
    
    if (!samechar) {
        int i = 0;
        int j = (int)s.size() - 1;
        bool palindrome = false;
        
        if (s.size() % 2 == 0) {
            while (1) {
                if (s[i] == s[j]) --j;
                ++i;
                
                if (i == s.size() / 2) {
                    if (i - j == 1) palindrome = true;
                    break;
                }
            }
        }
        else {
            while (1) {
                if (s[i] == s[j]) --j;
                ++i;
                
                if (i == (s.size() - 1) / 2) {
                    if (i == j) palindrome = true;
                    break;
                }
            }
        }
        
        R = (palindrome) ? (int)s.size() - 1 : (int)s.size();
    }
    else {
        R = -1;
    }
    
    return;
}


int main (int argc, const char* argv []) {
    
    std::cin >> s;
    solve();
    std::cout << R;
    return 0;
}
