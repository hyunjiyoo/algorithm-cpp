#include <iostream>
#include <stack>
#include <string>

std::string S, R;
std::stack<char> s;

void input() {
    std::getline(std::cin, S);
}

void print_stack() {
    while (!s.empty()) {
        R += s.top();
        s.pop();
    }
}

void solve() {
    
    for (int i = 0; i < int(S.length()); ++i) {
        
        if (S[i] == '<') {
            print_stack();
            
            while (S[i] != '>')
                R += S[i++];
            
            R += '>';
        }
        
        else if (S[i] == ' ') {
            print_stack();
            R += ' ';
        }
        
        else {
            s.push(S[i]);
        }
    }
    
    while (!s.empty()) {
        R += s.top();
        s.pop();
    }
    
    std::cout << R;
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
