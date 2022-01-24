#include <iostream>
#include <queue>

int64_t A, B, R;
std::queue<std::pair<int64_t, int>> q;
bool able;

void init() {
    able = false;
    q.push({A, 1});
}

void solve() {
    
    while (!q.empty()) {

        int64_t num = q.front().first;
        
        if (num == B) {
            able = true;
            R = q.front().second;
            return;
        }
        
        if (num * 2 <= B)
            q.push({num * 2, q.front().second + 1});
        
        if (num * 10 + 1 <= B)
            q.push({num * 10 + 1, q.front().second + 1});
        
        q.pop();
    }
}

void output() {
    
    if (able)
        std::cout << R;
    else
        std::cout << -1;
}


int main (int argc, const char * arvg []) {
 
    std::ios::sync_with_stdio(false);
    
    std::cin >> A >> B;
    
    init();
    solve();
    output();
    
    return 0;
}
