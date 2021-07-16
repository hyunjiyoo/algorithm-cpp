#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef struct {
    int seq;
    int weight;
} doc;

int C, N, M, R;
std::vector<int> w;
std::queue<doc> q;


void init() {
    R = 0;
    w.clear();
    while(!q.empty()) q.pop();
}

void input() {
    std::scanf("%d %d", &N, &M);
    w.resize(N);
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &w[i]);
        q.push({i, w[i]});
    }
    
    std::sort(w.begin(), w.end());
}

void solve() {
    
    while (!q.empty()) {
        
        int seq = q.front().seq;
        int weight = q.front().weight;
        
        if (weight == w.back()) {
            ++R;
            w.pop_back();
            
            if (seq == M) break;
        }
        else {
            q.push({seq, weight});
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
