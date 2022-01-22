#include <iostream>
#include <queue>

int R, C;
int sheep_total, wolf_total;
int sheep_cnt, wolf_cnt;
int field[250][250];
bool check[250][250];
std::queue<std::pair<int, int>> q;

const int offset[4][2] = {
    {0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

enum {
    empty = '.' - 'A',
    fence = '#' - 'A',
    sheep = 'o' - 'A',
    wolf = 'v' - 'A'
};

void input() {
    std::cin >> R >> C;
    
    sheep_total = wolf_total = 0;
    
    char input;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> input;
            field[i][j] = input - 'A';
            
            if (field[i][j] != fence)
                check[i][j] = true;
            
            if (field[i][j] == sheep)
                ++sheep_total;
            
            if (field[i][j] == wolf)
                ++wolf_total;
        }
    }
}

void init() {

    sheep_cnt = wolf_cnt = 0;

    for (int i = 0; i < R; ++i) {

        for (int j = 0; j < C; ++j) {
            
            if (check[i][j]) {
                check[i][j] = false;
                q.push({i, j});
                return;
            }
            
        }
    }
}


void search(int y, int x) {

    for (int i = 0; i < 4; ++i) {
        int ny = y + offset[i][0];
        int nx = x + offset[i][1];
        
        if (!(0 <= ny && ny < R) || !(0 <= nx && nx < C))
            continue;
        
        if (check[ny][nx]) {
           
            if (field[ny][nx] == sheep)
                ++sheep_cnt;
            
            if (field[ny][nx] == wolf)
                ++wolf_cnt;
            
            check[ny][nx] = false;
            search(ny, nx);
        }
    }
}

void solve() {

    while(!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        
        search(y, x);
        
        if (sheep_cnt > wolf_cnt)
            wolf_total -= wolf_cnt;
        else
            sheep_total -= sheep_cnt;
        
        bool flag = false;
        sheep_cnt = wolf_cnt = 0;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (check[i][j]) {
                    
                    if (field[i][j] == sheep)
                        ++sheep_cnt;
                    
                    if (field[i][j] == wolf)
                        ++wolf_cnt;
                    
                    q.push({i, j});
                    check[i][j] = false;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        q.pop();
    }
}

void output() {
    std::cout << sheep_total << ' ' << wolf_total;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    init();
    solve();
    output();
    
    return 0;
}
