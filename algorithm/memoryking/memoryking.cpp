#include <iostream>
#include <unordered_map>

int T, N, M;
std::unordered_map<int, bool> note1;
int note2[1'000'000];

void init() {
    N = M = 0;
    note1.clear();
    for (int i = 0; i < 1'000'000; ++i)
        note2[i] = 0;
}

void input() {
    int num1;
    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &num1);
        note1.insert({ num1, true });
    }
    
    std::scanf("%d", &M);
    for (int i = 0; i < M; ++i)
        std::scanf("%d", note2 + i);
}

void solve() {
    bool result;
    for (int i = 0; i < M; ++i) {
        if(note1[note2[i]])
            result = true;
        else
            result = false;
        
        printf("%d\n", result);
    }
}

int main (int argc, const char * argv []) {
    std::scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        init();
        input();
        solve();
    }
    
    return 0;
}
