#include <iostream>
#include <vector>

int N;
int w[11], h[11];
std::vector<std::vector<char>> star;

void init() {
    w[1] = h[1] = 1;
    for (int i = 1; i <= 10; ++i) {
        h[i] = h[i - 1] * 2 + 1;
        w[i] = h[i] * 2 - 1;
    }
}

void input() {
    std::scanf("%d", &N);
    star.resize(h[N]);
    for (int i = 0; i < h[N]; ++i)
        star[i].resize(w[N]);
    
    for (int i = 0; i < h[N]; ++i)
        for (int j = 0; j < w[N]; ++j)
            star[i][j] = ' ';
}

void print() {
    
    if (N % 2 == 0) {
        for (int i = 0; i < h[N]; ++i) {
            for (int j = 0; j < w[N] - i; ++j) {
                std::printf("%c", star[i][j]);
            }
            std::printf("\n");
        }
    }
    else {
        for (int i = 0; i < h[N]; ++i) {
            for (int j = 0; j <= (w[N] / 2) + i; ++j) {
                std::printf("%c", star[i][j]);
            }
            std::printf("\n");
        }
    }
}

void solve(int x = 0, int y = 0, int step = N) {
    
    if (step == 0) return;
    
    if (step % 2 == 0) {
        for (int i = x; i < x + w[step]; ++i) {
            star[y][i] = '*';
        }
        
        int j = 1;
        for (int i = y + 1; i < y + h[step]; ++i) {
            star[i][x + j] = '*';
            star[i][x + (w[step] - 1) - j] = '*';
            ++j;
        }
        solve(x + (w[step]/2) - (w[step-1]/2), y + 1, step - 1);
    }
    else {
        for (int i = x; i < x + w[step]; ++i) {
            star[y + (h[step] - 1)][i] = '*';
        }
        
        int j = 1;
        for (int i = y + (h[step] - 1) - 1; i >= y; --i) {
            star[i][x + j] = '*';
            star[i][x + (w[step] - 1) - j] = '*';
            ++j;
        }
        solve(x + (w[step]/2) - (w[step-1]/2), y + (h[step]/2), step - 1);
    }
}


int main (int argc, const char* argv []) {
    
    init();
    input();
    solve();
    print();
    
    return 0;
}
