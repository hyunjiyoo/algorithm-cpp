#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int T, N;
std::vector<std::pair<int, int>> v;

void init() {
    v.clear();
}

void input() {
    std::cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> v[i].first >> v[i].second;
    
    std::sort(v.begin(), v.end());
}

void solve() {
    
    int count = 0;
    int min = std::numeric_limits<int>::max();
    
    for (int i = 0; i < N; ++i) {
        if (v[i].second < min) {
            min = v[i].second;
            ++count;
        }
    }
    
    std::cout << count << std::endl;
}


int main (int argc, const char * argv []) {
    
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> T;
    
    for (int i = 0; i < T; ++i) {
        init();
        input();
        solve();
    }
    
    return 0;
}
