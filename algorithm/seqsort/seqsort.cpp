#include <iostream>
#include <algorithm>

using pair = std::pair<int, int>;

int N;
pair A[50];
int P[50];

void input() {
    std::scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int n;
        std::scanf("%d", &n);
        A[i] = {n, i};
    }
}

void solve() {
    std::sort(A, A + N);
    for (int i = 0; i < N; ++i)
        P[A[i].second] = i;
    
    for (int i = 0; i < N; ++i)
        std::printf("%d ", P[i]);
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
