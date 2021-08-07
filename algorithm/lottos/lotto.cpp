#include <iostream>
#include <vector>

int k;
int lotto[6];
std::vector<int> S;

void init() {
    S.clear();
}

void input() {
    S.resize(k);
    for (int i = 0; i < k; ++i)
        std::cin >> S[i];
}

void solve(int step = 0, int num = 0) {
    
    if (step == 6) {
        for (int i : lotto)
            std::cout << i << ' ';
        std::cout << std::endl;
        return;
    }
    
    for (int i = num; i < S.size(); ++i) {
        lotto[step] = S[i];
        solve(step + 1, i + 1);
    }
}

int main (int argc, const char * argv []) {
    
    while (true) {
        std::cin >> k;
        if (k == 0)
            break;
        
        init();
        input();
        solve();
        std::cout << '\n';
    }
    
    return 0;
}
