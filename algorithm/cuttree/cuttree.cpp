#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> tree;

void input() {
    std::cin >> N >> M;
    tree.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> tree[i];
    
    std::sort(tree.begin(), tree.end());
}

void solve() {
    
    int64_t left = tree[0];
    int64_t right = tree[N - 1];
    
    while (left <= right) {
        
        int64_t mid = (left + right) / 2;
        
        int64_t sum = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (tree[i] < mid) break;
            sum += (tree[i] - mid);
            if (sum >= M) break;
        }
        
        if (sum == M) {
            std::cout << mid;
            break;
        }
        
        if (sum > M)
            left = mid;
        
        if (sum < M)
            right = mid;
    }
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
