#include <iostream>
#include <algorithm>
#include <vector>

int N;
int asc_cnt, desc_cnt;
int asc_max, desc_max;
std::vector<int> v;

void input() {
    std::cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> v[i];
    
    asc_cnt = desc_cnt = 1;
    asc_max = desc_max = 1;
}


void increase(int basis, int count = 1) {
    
    if ((basis == N - 1) || (v[basis] > v[basis + 1])) {
        asc_cnt = count;
        return;
    }
    
    increase(basis + 1, count + 1);
}

void decrease(int basis, int count = 1) {
    
    if ((basis == N - 1) || (v[basis] < v[basis + 1])) {
        desc_cnt = count;
        return;
    }
    
    decrease(basis + 1, count + 1);
}


void solve() {
    
    for (int i = 0; i < N - 1; i += asc_cnt) {
        if (N - i <= asc_max) break;
        
        increase(i);
        
        if (asc_max < asc_cnt)
            asc_max = asc_cnt;
    }
    
    for (int i = 0; i < N - 1; i += desc_cnt) {
        if (N - i <= desc_max) break;
        
        decrease(i);
        
        if (desc_max < desc_cnt)
            desc_max = desc_cnt;
    }
    
    std::cout << std::max(asc_max, desc_max);
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
