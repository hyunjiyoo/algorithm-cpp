#include <iostream>
#include <cstring>

int N, RT, P;
int ZOO[100'001][3];

enum { L = 0, R = 1, T = 2 };

void init();
void input();
void solve();
void result();
int moduler(int);

int main(int argc, const char* argv[]) {
    
    init();
    input();
    solve();
    result();
    
    return 0;
}

void init() {
    std::memset(ZOO, 0, sizeof ZOO);
    N = RT = 0;
    P = 9'901;
}

void input() {
    std::scanf("%d", &N);
}

void solve() {
    ZOO[0][T] = 1;
    
    for (int i = 1; i <= N; ++i) {
        ZOO[i][L] = moduler(ZOO[i - 1][T] - ZOO[i - 1][L]);
        ZOO[i][R] = moduler(ZOO[i - 1][T] - ZOO[i - 1][R]);
        ZOO[i][T] = moduler(ZOO[i - 1][T] + ZOO[i][L] + ZOO[i][R]);
    }
    
    RT = ZOO[N][T];
}

void result() {
    std::printf("%d", RT);
}

int moduler(int n) {
    return (n + P) % P;
}
