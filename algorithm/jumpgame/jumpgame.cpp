#include <iostream>

int n;
int JUMP[100][100];
bool X[100][100];

void input() {
    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::scanf("%d", &JUMP[i][j]);
        }
    }
    
}

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            X[i][j] = false;
        }
    }
}

bool solve(int i = 0, int j = 0) {

    // 목적지에 도달하면 true
    if (i == n - 1 && j == n - 1) {
        return true;
    }
    
    // 범위밖을 벗어나면 false
    if (i >= n || j >= n) {
        return false;
    }
    
    // 방문하면 안되는 X가 비활성화이면 이동
    if (!X[i][j]) {
        
        // 아래로 이동하다가 범위밖을 넘어가서.false를 리턴받으면 오른쪽으로 이동
        if (solve(i + JUMP[i][j], j)) {
            return true;
        }
        
        // 오른쪽으로 이동하다가 범위밖을 넘어가서 false를 리턴받으면
        // 해당 위치에서는 더이상 목적지로 갈 수 없기때문에 방문할 필요가 없음.
        if (solve(i, j + JUMP[i][j])) {
            return true;
        }
        // 방문하면 안되는 flag를 true로 설정
        X[i][j] = true;
    }
    
    return false;
}


int main(int argc, const char* argv []) {
    int C;
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        input();
        init();
        
        bool reachable = solve();
        
        if (reachable)
            std::printf("YES\n");
        else
            std::printf("NO\n");
    }
    
    return 0;
}
