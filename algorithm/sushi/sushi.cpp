#include <iostream>
#include <limits>
#include <vector>

int N, d, k, c;
std::vector<int> sushi;
std::vector<int> check;


void input() {
    std::scanf("%d %d %d %d", &N, &d, &k, &c);
    sushi.resize(N + k);
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &sushi[i]);
    
    for (int i = 0; i < k; ++i)
        sushi[N + i] = sushi[i];
    
    check.resize(d + 1, 0);
}


void solve() {
    int i = 0;
    int max = std::numeric_limits<int>::min();
    int count = 0;
    
    ++check[c];
    ++count;
    
    for (; i < k; ++i) {
        if (check[sushi[i]] == 0)
            ++count;
        ++check[sushi[i]];
    }
    
    while (i < N + k) {
        --check[sushi[i - k]];
        if (check[sushi[i - k]] == 0)
            --count;
        
        ++check[sushi[i]];
        if (check[sushi[i]] == 1) {
            ++count;
            if (max < count)
                max = count;
        }
        
        ++i;
    }
    
    std::printf("%d", max);
}


int main (int argc, const char * argv []) {

    input();
    solve();
    
    return 0;
}
