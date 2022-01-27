#include <iostream>
#include <cmath>

int N, M;
int CANDY[301][301];
int DP[301][301];

void input() {
    std::scanf("%d %d", &N, &M);
   
    std::fill_n((int*)DP, 301 * 301, -1);
    
    int y, x;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d %d", &y, &x);
        CANDY[y][x] = std::max(0, M - y - x);
    }
}

void bfs(int y = 0, int x = 0, int count = 0) {

    if (y > 300 or x > 300)
        return;
    
    count += CANDY[y][x];

    if (DP[y][x] != -1)
        if (DP[y][x] < count)
            DP[y][x] = count;
        else
            return;
    else
        DP[y][x] = count;
    
    bfs(y + 1, x, DP[y][x]);
    bfs(y, x + 1, DP[y][x]);
}


int main (int argc, const char * argv []) {

    input();
    bfs();
    std::printf("%d", DP[300][300]);
    
    return 0;
}
