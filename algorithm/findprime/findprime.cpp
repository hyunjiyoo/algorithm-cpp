#include <iostream>
#include <vector>

int N, R;
std::vector<int> num;
std::vector<bool> prime;


void input() {
    std::scanf("%d", &N);
    
    num.resize(N);
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &num[i]);
    }
}


void init() {
    R = 0;
    prime.resize(1'001);
    std::fill_n(prime.begin(), 1'001, true);
    prime[0] = prime[1] = false;
}

void solve() {
    
    for (int i = 2; i <= 1'000; ++i) {
        int j = 2;
        while (i * j <= 1'000) {
            prime[i * j++] = false;
        }
    }
    
    for (int i : num) {
        if (prime[i])
            ++R;
    }
    
    std::printf("%d", R);
}

int main (int argc, const char * argv []) {
    
    input();
    init();
    solve();
        
    return 0;
}
