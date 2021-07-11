#include <iostream>
#include <string>
#include <stack>

std::string str;
std::stack<char> s;

void solve() {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            s.push('2');
            
            if (i < str.size() - 1) {
                
                if (str[i + 1] == '(' || str[i + 1] == '[')
                    s.push('*');
                
            }
        }
        
        else if (str[i] == '[') {
            s.push('3');
            
            if (i < str.size() - 1) {
                
                if (str[i + 1] == '(' || str[i + 1] == '[')
                    s.push('*');
            }
            
        }
        else {
            s.push('=');
        }
    }

    
    
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> str;
    solve();
    
    
    return 0;
}
