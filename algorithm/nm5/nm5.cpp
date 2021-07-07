#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<bool> chk;
std::vector<int> numbers, v;


void init() {
    std::scanf("%d %d", &N, &M);
    v.resize(M);
    chk.resize(N);
    
    numbers.resize(N);
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &numbers[i]);
    
    std::sort(numbers.begin(), numbers.end());
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
        
        v[step] = numbers[i];
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
