#include <iostream>
#include <algorithm>
#include <queue>

using pair = std::pair<int, int>;

int N;
std::priority_queue<pair, std::vector<pair>, std::greater<pair>> t;
std::priority_queue<int, std::vector<int>, std::greater<int>> lec;


void input() {
    std::scanf("%d", &N);
    int n, s, e;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d %d %d", &n, &s, &e);
        t.push(std::make_pair(s, e));
    }
}

void solve() {
    int count = 1;
    std::pair<int, int> top;
    
    while (!t.empty()) {
        top = t.top();
        lec.push(top.second);
        t.pop();
        
        while (!lec.empty() && lec.top() <= top.first)
            lec.pop();
        
        count = std::max(count, (int)lec.size());
    }
    
    std::printf("%d", count);
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
