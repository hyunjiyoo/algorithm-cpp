#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;

void init() {
    std::scanf("%d %d", &N, &M);
    v.resize(M);
}

void solve(int step = 0) {
    
    if (step == M) {

        for (int num : v)
            std::printf("%d ", num);
        std::printf("\n");
        
        return;
    }
    
    for (int i = 1; i <= N; ++i) {
        v[step] = i;
        solve(step + 1);
    }
}

int main (int argc, const char * argv []) {
    
    init();
    solve();
    
    return 0;
}
