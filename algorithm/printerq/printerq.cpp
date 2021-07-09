#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int C, N, M, R;
std::vector<int> v;
std::queue<std::pair<int, int>> q;

void init() {
    
    R = 0;
    v.clear();
    
    while(!q.empty()) q.pop();
}

void input() {
    
    std::scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i) {
        int w;
        std::scanf("%d", &w);
        v.push_back(w);
        q.push({i, w});
    }
    
    std::sort(v.begin(), v.end());
}


void solve() {
    
    while (!q.empty()) {
    
        int n = q.front().first;
        int w = q.front().second;
        
        if (w == v.back()) {
            v.pop_back();
            ++R;
            
            if (n == M) break;
        }
        else {
            q.push(q.front());
        }
        
        q.pop();
    }
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        init();
        input();
        solve();
        std::printf("%d\n", R);
    }
    
    return 0;
}
