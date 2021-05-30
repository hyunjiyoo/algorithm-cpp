#include <iostream>

int n;
int score[500][500];
int result = -1;
int DP[500][500];


void init() {
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::scanf("%d", &score[i][j]);
            if (std::cin.get() == '\n')
                break;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            DP[i][j] = -1;
        }
    }
    
    DP[0][0] = score[0][0];
    for (int i = 1; i < n; ++i) {
        DP[i][0] = DP[i-1][0] + score[i][0];
    }
}

int solve(int y, int x) {
    if (x > y)
        return 0;
        
    if (DP[y][x] == -1)
        DP[y][x] = std::max(solve(y-1, x-1), solve(y-1, x)) + score[y][x];
            
    return DP[y][x];
}


int main(int argc, const char* argv[]) {
    std::scanf("%d", &n);
    
    init();

    for (int i = 0; i < n; ++i)
        result = std::max(result, solve(n-1, i));

    std::printf("%d", result);
    
    return 0;
}
