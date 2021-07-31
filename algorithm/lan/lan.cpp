#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int K, N, maxv;
std::vector<int> LAN;

void input() {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> K >> N;
    LAN.resize(K);
    maxv = std::numeric_limits<int>::min();
    
    for (int i = 0; i < K; ++i) {
        std::cin >> LAN[i];
        maxv = std::max(maxv, LAN[i]);
    }
}


bool countLan(int64_t lan) {
    
    int count = 0;
    for (int i = 0; i < K; ++i) {
        count += (LAN[i] / lan);
        
        if (count > N)
            break;
    }
    
    return count >= N;
}


void solve() {
    
    int64_t left = 1;
    int64_t right = maxv;
    int64_t mid = (left + right) / 2;
    
    while (left <= right) {
        
        if (countLan(mid))
            left = mid + 1;
        else
            right = mid - 1;
        
        mid = (left + right) / 2;
    }
    
    std::cout << left - 1;
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
