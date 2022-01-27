#include <iostream>
#include <algorithm>
#include <vector>

int N, R, CNT;
std::vector<bool> picked;
std::vector<int> bead, v;

void input() {
    
    std::cin >> N;
    bead.resize(N);
    picked.resize(N);
    
    for (int i = 0; i < N; ++i)
        std::cin >> bead[i];
    
    R = CNT = 0;
}

void solve(int step = 0) {
    
    if (step == N - 2) {
        R = std::max(R, CNT);
        return;
    }
    
    for (int i = 1; i < N - 1; ++i) {
        
        if (!picked[i]) {
            picked[i] = true;
            
            int prev, next;
            prev = next = 0;
            
            for (int j = i - 1; j >= 0; --j) {
                if (!picked[j]) {
                    prev = bead[j];
                    break;
                }
            }
            
            for (int j = i + 1; j < N; ++j) {
                if (!picked[j]) {
                    next = bead[j];
                    break;
                }
            }
            
            CNT += (prev * next);
            solve(step + 1);
            picked[i] = false;
            CNT -= (prev * next);
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    std::cout << R;
    
    return 0;
}
