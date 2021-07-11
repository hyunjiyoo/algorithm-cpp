#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> score;

void input() {
    std::scanf("%d", &N);
    score.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &score[i]);
    }
    
    std::sort(score.begin(), score.end());
}

void solve() {
    
    int i = 0;
    for (; i < N; ++i) {
        
        bool flag = true;
        int s = N - 1 - i;
        for (int j = i + 1; j < N; ++j) {
            if (score[i] + N < score[j] + s--) {
                flag = false;
                break;
            }
        }
        
        if (flag) break;
    }
    
    std::printf("%d", N - i);
}

int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
