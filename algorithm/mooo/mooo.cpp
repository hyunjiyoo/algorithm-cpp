#include <iostream>
#include <vector>

int N, pos;
std::vector<int> v;

void solve();

void input() {
    
    v.push_back(3);
    int i = 1;
    for (; i < 30; ++i) {
        v.push_back(2 * v[i - 1] + 3 + i);
        if (v[i] >= N) break;
    }
    
    pos = i;
    solve();
}

void solve() {
    
    if (N == 1)
        std::cout << 'm';
    
    else if (N == 2 || N == 3)
        std::cout << 'o';
    
    else if (N == v[pos - 1] + 1)
        std::cout << 'm';
    
    else if (v[pos - 1] + 1 < N && N <= v[pos - 1] + pos + 3)
        std::cout << 'o';
    
    else {
        N -= (v[pos - 1] + pos + 3);
        v.clear();
        input();
    }
    
    return;
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;
    
    input();
    
    return 0;
}
