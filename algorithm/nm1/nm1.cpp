#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;
std::vector<bool> chk;

void init() {
    std::scanf("%d %d", &N, &M);
    v.resize(M);
    chk.resize(N);
}

void solve(int step = 0) {
    
    if (step == M) {
        
        for (int num : v)
            std::printf("%d ", num);
        std::printf("\n");
        
        return;
    }
    
    for (int i = 0; i < N; ++i) {
        
        if (chk[i]) continue;
        
        v[step] = i + 1;
        chk[i] = true;
        solve(step + 1);
        chk[i] = false;
    }
}


int main (int argc, const char * argv []) {
    
    init();
    solve();
    
    return 0;
}
