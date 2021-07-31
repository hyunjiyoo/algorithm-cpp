#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int N, M;
std::vector<int> v;

void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    v.resize(N);
    
    for (int i = 0; i < N; ++i)
        std::cin >> v[i];
}

bool allowance(int m) {
    
    int balance = m;
    int count = 1;
    for (int i = 0; i < N; ++i) {
        if (balance - v[i] < 0) {
            count++;
            balance = m;
        }
        
        balance -= v[i];
    }
    
    return count <= M;
}

void solve() {
    
    int left = *std::max_element(v.begin(), v.end());
    int right = std::accumulate(v.begin(), v.end(), 0);
    int mid = (left + right) / 2;
    
    while (left <= right) {
        
        if (allowance(mid))
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
