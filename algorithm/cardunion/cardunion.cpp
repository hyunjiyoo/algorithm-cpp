#include <iostream>
#include <algorithm>

int n, m;
int64_t card[1'000];
int64_t R;

void solve() {
    
    for (int i = 0; i < m; ++i) {
        std::sort(card, card + n);
        
        card[0] += card[1];
        card[1] = card[0];
    }
    
    R = 0;
    for (int i = 0; i < n; ++i) {
        R += card[i];
    }
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        std::scanf("%lld", card + i);
    }
    
    solve();
    std::printf("%lld", R);
    
    return 0;
}
