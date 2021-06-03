#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> card, num, R;

void input() {
    std::scanf("%d", &N);
    card.resize(N);
    for (int i = 0; i < N; ++i)
        std::scanf("%d", &card[i]);
    
    std::sort(card.begin(), card.end());
}

void solve() {
    std::scanf("%d", &M);
    num.resize(M);
    R.resize(M);
    std::fill_n(R.begin(), M, 0);
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", &num[i]);
        if (std::binary_search(card.begin(), card.end(), num[i]))
            R[i] = 1;
    }
}

void output() {
    for (int i = 0; i < R.size(); ++i)
        std::printf("%d ", R[i]);
}

int main (int argc, const char* argv []) {
    
    input();
    solve();
    output();
    
    return 0;
}
