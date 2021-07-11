#include <iostream>
#include <cstring>

int N;
int num[100];
bool prime[1'001];

void input() {
    std::scanf("%d", &N);
    
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &num[i]);
    
    std::memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
}

void solve() {
 
    for (int i = 2; i < 1'001; ++i) {
        if (prime[i] == false)
            continue;
        
        int j = 2;
        while (i * j < 1'001) {
            prime[i * j++] = false;
        }
    }
    
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (prime[num[i]])
            ++count;
    }
    
    std::printf("%d", count);
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
