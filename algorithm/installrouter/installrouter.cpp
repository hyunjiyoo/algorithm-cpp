#include <iostream>
#include <algorithm>
#include <vector>

int N, C;
std::vector<int> home;

void input() {
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> C;
    home.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> home[i];
    
    std::sort(home.begin(), home.end());
}

bool installRouter(int64_t dist) {
    
    int count = 1;
    int64_t basis = home[0];
    for (int i = 0; i < N; ++i) {
        
        if (home[i] - basis >= dist) {
            ++count;
            basis = home[i];
        }
        
        if (count > C) break;
    }
    
    return count >= C;
}


void solve() {
    
    int64_t left = 1;
    int64_t right = home[N - 1] - home[0];
    int64_t mid = (left + right) / 2;
    
    while (left <= right) {
        
        if (installRouter(mid))
            left = mid + 1;
        else
            right = mid - 1;
        
        mid = (left + right) / 2;
    }
    
    std::cout << left - 1;
}

int main(int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
