#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> budget;

void input() {
    std::scanf("%d", &N);
    budget.resize(N);
    
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &budget[i]);
    }
    std::scanf("%d", &M);
}

int solve() {
    std::sort(budget.begin(), budget.end());
    
    int low = 0;
    int high = budget[N - 1];
    int mid = budget[N - 1] / 2;
    int sum;
    
    while (high >= low) {
        sum = 0;
        
        for (int i = 0; i < N; ++i) {
            sum += (mid < budget[i]) ? mid : budget[i];
        }
        
        if (sum == M) return mid;
        
        if (sum < M)
            low = mid + 1;
        else
            high = mid - 1;
        
        mid = (low + high) / 2;
    }
    
    return mid;
}

int main (int argc, const char * argv []) {

    input();
    std::printf("%d", solve());
    
    return 0;
}
