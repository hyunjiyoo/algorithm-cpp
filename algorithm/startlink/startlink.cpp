#include <iostream>
#include <vector>
#include <queue>

int F, S, G, U, D;
std::queue<int> q;
std::vector<int> v;

void init() {
    v.resize(F + 1);
    std::fill_n(v.begin(), F + 1, -1);
    v[S] = 0;
    q.push(S);
}

void solve() {
    
    while (!q.empty()) {
        if (v[G] != -1)
            break;
        
        int pos = q.front();
        
        if (pos + U <= F && v[pos + U] == -1) {
            q.push(pos + U);
            v[pos + U] = v[pos] + 1;
        }
        
        if (pos - D > 0 && v[pos - D] == -1) {
            q.push(pos - D);
            v[pos - D] = v[pos] + 1;
        }
        
        q.pop();
    }
}

void output() {
    if (v[G] == -1)
        std::printf("use the stairs");
    else
        std::printf("%d", v[G]);
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    
    init();
    solve();
    output();
    
    return 0;
}
