#include <iostream>
#include <vector>

int N, M;
std::vector<int> staff;

void input() {
    std::scanf("%d %d", &N, &M);
    staff.resize(N);
    
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &staff[i]);
}

void solve() {
    int64_t sum;
    int64_t low = 0;
    int64_t high = 1000000000001LL;
    int64_t mid = (low + high) / 2;
    
    while (high > low + 1) {
        sum = 0;
        for (int i = 0; i < N; ++i)
            sum += (mid / staff[i]);
        
        if (sum >= M)
            high = mid;
        else
            low = mid;
        
        mid = (low + high) / 2;
    }
    
    std::printf("%lld", high);
}

int main (int argc, const char * argv []) {
    input();
    solve();
    
    return 0;
}
