#include <iostream>
#include <cmath>

int64_t N, R;
int64_t MAP[10][10];

void init() {

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            MAP[i][0] = MAP[0][j] = 1;
        }
    }
    
    MAP[0][0] = 0;
    
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10 - i; ++j) {
            MAP[i][j] = MAP[i][j - 1] + MAP[i - 1][j];
        }
    }
}

void findIdx(int64_t y, int64_t n) {
    
    if (y < 0 || n == 0)
        return;
    
    for (int i = 0; i < 10; ++i) {
        n -= MAP[y][i];
        
        if (n <= 0) {
            R += (std::pow(10, y) * (y + i));
            findIdx(y - 1, MAP[y][i] + n);
            break;
        }
    }
}

void solve() {
    
    int64_t y, x;
    bool flag = false;
    y = x = 0;
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            N -= MAP[i][j];
            
            if (N <= 0) {
                R = (std::pow(10, i) * (i + j));
                y = i;
                x = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    
    findIdx(y - 1, MAP[y][x] + N);
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> N;
    
    if (N < 10) {
        R = N;
    }
    else {
        init();
        
        if (N < 1023) {
            solve();
            R -= 1;
        }
        else {
            R = -1;
        }
    }
    
    std::cout << R;
    
    return 0;
}
