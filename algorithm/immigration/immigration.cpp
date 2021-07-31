#include <iostream>
#include <algorithm>
#include <vector>

int64_t N, M;
std::vector<int> T;

void input() {
    
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    T.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> T[i];
    
    std::sort(T.begin(), T.end());
}

bool countImmig(int64_t t) {
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        count += (t / T[i]);
        
        if (count > M) break;
    }
    
    return count >= M;
}


void solve() {
    
    int64_t left = T[0];
    int64_t right = T[0] * M;
    int64_t mid = (left + right) / 2;
    
    while (left <= right) {
        
        if (countImmig(mid))
            right = mid - 1;
        else
            left = mid + 1;
            
        mid = (left + right) / 2;
    }
    
    std::cout << left;
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
