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
    
    int left = 0;
    int right = tree[N - 1];
    int mid = (left + right) / 2;
    
    while (left <= right) {
        
        int64_t sum = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (tree[i] <= mid) break;
            sum += (tree[i] - mid);
            if (sum > M) break;
        }
        
        if (sum == M)
            break;
        
        if (sum > M)
            left = mid + 1;
        
        if (sum < M)
            right = mid - 1;
        
        mid = (left + right) / 2;
    }
    
    std::cout << mid;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
