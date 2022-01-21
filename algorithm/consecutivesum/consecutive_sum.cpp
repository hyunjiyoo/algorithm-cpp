#include <iostream>
#include <algorithm>
#include <limits>

int n;
int num[100'001];
int sum[100'001];
int sum_min[100'001];

void input() {
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> num[i + 1];
    }
    
    sum[0] = num[0] = sum_min[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + num[i];
        sum_min[i] = std::min(sum_min[i - 1], sum[i]);
    }
}

void solve() {
    
    int max = std::numeric_limits<int>::min();
    
    for (int i = 1; i <= n; ++i) {
        max = std::max(max, sum[i] - sum_min[i - 1]);
    }
    
    std::cout << max;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
