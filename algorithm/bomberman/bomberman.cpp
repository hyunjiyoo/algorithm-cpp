#include <iostream>
#include <string>
#include <vector>
#include <queue>

int R, C, N;

std::vector<std::vector<int>> v;
std::queue<std::pair<int, int>> q;

const int offset[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void input() {
    
    std::cin >> R >> C >> N;
    v.resize(R);
    
    std::string str;
    for (int i = 0; i < R; ++i) {
        std::cin >> str;
        
        for (int j = 0; j < C; ++j) {
            if (str[j] == '.')
                v[i].push_back(0);
            
            if (str[j] == 'O')
                v[i].push_back(1);
        }
    }
}

void output() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (v[i][j] == 0)
                std::cout << '.';
            else
                std::cout << 'O';
        }
        
        std::cout << std::endl;
    }
}

void bomb(int y, int x) {
    
    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < R) || !(0 <= nx && nx < C))
            continue;
        
        v[ny][nx] = 0;
    }
}


void setBomb() {
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            ++v[i][j];
}


bool foundBomb() {
    
    bool flag = false;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (v[i][j] == 2) {
                q.push({i, j});
                flag = true;
            }
        }
    }
    
    return flag;
}


void solve(int step = 1) {

    if (step == N)
        return;
    
    if (foundBomb()) {
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            
            v[y][x] = 0;
            bomb(y, x);
            
            q.pop();
        }
    }
    else {
        setBomb();
    }
    
    solve(step + 1);
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    
    if (N > 1)
        solve();

    output();
    
    return 0;
}
