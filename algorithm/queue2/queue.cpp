#include <iostream>
#include <string>
#include <queue>

int N, R;
std::queue<int> q;

void solve() {
    std::string str;
    std::cin >> str;
    
    if (str[1] == 'u') {
        int x;
        std::cin >> x;
        q.push(x);
    }
    else {
        R = -1;
        
        if (str[1] == 'i')
            R = (int)q.size();
        
        else if (str[1] == 'm')
            R = q.empty();
        
        else if (!q.empty()) {
            if (str[1] == 'o') {
                R = q.front();
                q.pop();
            }
            
            if (str[1] == 'r')
                R = q.front();
            
            if (str[1] == 'a')
                R = q.back();
            
        }
        
        std::cout << R << std::endl;
    }
}

int main(int argc, const char* argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        solve();
    }
    
    return 0;
}
