#include <iostream>

int N;
int M;
int VIP[40];
int DP[41][41];

// 이 점화식은 VIP 위치를 무조건 양끝에 몰아넣을때의 경우의 수만 생각했다.
// 예를 들어 여기서 DP[5][2] = 3 이 나오는데
// VIP가 2번째, 4번째 자리에 있을 경우 DP[5][2] = 1 이 나온다.

void input() {
    std::scanf("%d\n%d", &N, &M);
    
    for (int i = 0; i < M; ++i) {
        std::scanf("%d", VIP + i);
    }
}


void init() {
    DP[2][0] = 2;
    for (int i = 1; i < N + 1; ++i) {
        for (int j = i - 1; j <= i; ++j) {
            DP[i][j] = 1;
        }
    }
}


void solve() {
    for (int i = 3; i < N + 1; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j + 1];
        }
    }
}

int main(int argc, const char * argv []) {
    
    input();
    init();
    solve();
    
    std::printf("%d", DP[N][M]);
    
    return 0;
}
