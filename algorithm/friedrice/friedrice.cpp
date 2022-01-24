#include <iostream>
#include <algorithm>

int64_t D, N, M, K;

void input() {
    std::cin >> D >> N >> M >> K;
}

void solve() {
    int64_t rice = K;
    int64_t rest = K % D;
    int64_t need1 = D - std::max(N % D, M % D);
    int64_t need2 = D - std::min(N % D, M % D);
    
    
    if ((rest < need1 + need2) && (need1 <= rest)) {
        rice -= need1;
    }
    else {
        if (need2 <= (rest + D - need1))
            rice -= (need1 + need2);
    }
    
    std::cout << rice;
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
