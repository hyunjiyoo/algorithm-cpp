#include <iostream>

int N, M;
int num[100'001];
bool visited[100'001];

void input() {
    std::cin >> N >> M;
        
    int X, Y;
    for (int i = 0; i < M; ++i) {
        std::cin >> X >> Y;
        ++num[X];
        --num[Y];
    }
}

void solve() {
    
    for (int i = 1; i <= N; ++i) {
        num[i] += i;
        visited[num[i]] = true;
    }
    
    bool able = true;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            able = false;
            break;
        }
    }
    
    if (!able)
        std::cout << -1;
    else
        for (int i = 1; i <= N; ++i)
            std::cout << num[i] << ' ';
}



int main (int argc, const char* argv []) {
    
    input();
    solve();
    
    return 0;
}
