#include <iostream>

int N;
char star[2'187][2'187];

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            star[i][j] = '*';
        }
    }
}

void solve(int y = 0, int x = 0, int size = N) {

    if (size == 0)
        return;
    
    int offset = size / 3;
    
    for (int i = y + offset; i < y + offset * 2; ++i) {
        for (int j = x + offset; j < x + offset * 2; ++j) {
            star[i][j] = ' ';
        }
    }
    
    solve(y, x, offset);
    solve(y + offset, x, offset);
    solve(y + offset * 2, x, offset);
    
    solve(y, x + offset, offset);
    solve(y, x + offset * 2, offset);
    solve(y + offset, x + offset, offset);
    
    solve(y + offset * 2, x + offset, offset);
    solve(y + offset, x + offset * 2, offset);
    solve(y + offset * 2, x + offset * 2, offset);
}


void output() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << star[i][j];
        }
        std::cout << std::endl;
    }
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    
    init();
    solve();
    output();
    
    return 0;
}
