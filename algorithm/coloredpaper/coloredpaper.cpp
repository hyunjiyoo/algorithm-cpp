#include <iostream>

int N, power;
int blue_cnt, white_cnt;
bool paper[128][128];

void input() {
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> paper[i][j];
        }
    }
    
    blue_cnt = white_cnt = 0;
}

void solve(int y = 0, int x = 0, int len = N) {
    
    if (len == 0)
        return;
    
    int basis = paper[y][x];
    
    for (int i = y; i < y + len; ++i) {
        
        for (int j = x; j < x + len; ++j) {
            
            if (basis != paper[i][j]) {
                int offset = len / 2;
                
                solve(y, x, offset);
                solve(y + offset, x, offset);
                solve(y, x + offset, offset);
                solve(y + offset, x + offset, offset);
                
                return;
            }
        }
    }
    
    if (basis == 1) {
        ++blue_cnt;
    } else {
        ++white_cnt;
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    std::cout << white_cnt << std::endl;
    std::cout << blue_cnt << std::endl;
    
    return 0;
}
