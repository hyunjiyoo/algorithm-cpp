#include <iostream>

int N;
int SEQ[1'000];
int DP[1'000];

void input() {
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> SEQ[i];
        DP[i] = 1;
    }
}

void solve() {
    
    int max = 1;
    
    for (int i = 1; i < N; ++i) {
        
        int count = 0;
        
        for (int j = 0; j < i; ++j) {
      
            if (SEQ[j] >= SEQ[i]) continue;
            
            if (count < DP[j])
               count = DP[j];
        }
        
        DP[i] += count;
        max = std::max(max, DP[i]);
    }
    
    std::cout << max;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
