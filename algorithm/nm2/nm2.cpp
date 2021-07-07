#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;

void solve(int step = 0, int n = 0) {
    
    if (step == M) {
        for (int num : v)
            std::printf("%d ", num);
        std::printf("\n");
            
        return;
    }
    
    for (int i = n + 1; i <= N; ++i) {
        v[step] = i;
        solve(step + 1, i);
    }
    
}

int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &N, &M);
    v.resize(M);
    solve();
    
    return 0;
}
