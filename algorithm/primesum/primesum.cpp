#include <iostream>
#include <vector>

int N, count;
std::vector<int> prime;
std::vector<bool> PC;

void input() {
    std::scanf("%d", &N);
    
    PC.resize(N + 1, true);
    for (int i = 2; i <= N; ++i) {
        if (PC[i] == false)
            continue;
        
        int j = 2;
        while (i * j <= N)
            PC[i * j++] = false;
    }
    
    for (int i = 2; i <= N; ++i)
        if (PC[i] == true)
            prime.push_back(i);

    prime.push_back(0);
    count = 0;
}

void solve() {
    
    int left = 0;
    int right = 1;
    int sum = prime[left];
    while (left < prime.size()) {
        
        while (sum < N && right < prime.size())
            sum += prime[right++];
        
        if (sum > N) {
            sum -= prime[right - 1];
            --right;
        }
        
        if (sum == N)
            ++count;
        
        sum -= prime[left];
        ++left;
    }
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    std::printf("%d", count);

    return 0;
}
