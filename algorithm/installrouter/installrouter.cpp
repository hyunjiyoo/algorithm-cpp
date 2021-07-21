#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

int N, C;
std::vector<int> home, router;

void input() {
    std::cin >> N >> C;
    home.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> home[i];
    }
    
    std::sort(home.begin(), home.end());
    
    router.push_back(home[0]);
    router.push_back(home[N - 1]);
}


void solve() {
    
    int idx = 0;
    int left = home[0];
    int right = home[N - 1];
    
    for (int i = 0; i < C - 2; ++i) {
    
        int mid = (left + right) / 2;
        int min = std::numeric_limits<int>::max();
        for (int j = 1; j < N - 1; ++j) {
            if (min > std::abs(mid - home[j])) {
                min = std::abs(mid - home[j]);
                idx = j;
            }
        }
        
        router.push_back(home[idx]);
        
        if (idx < N / 2)
            left = home[idx];
        
         if (idx > N / 2)
            right = home[idx];
    }
    
    std::sort(router.begin(), router.end());
}


void output() {
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < C - 1; ++i) {
        min = std::min(min, router[i + 1] - router[i]);
    }
    
    std::cout << min;
}

int main(int argc, const char * argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
