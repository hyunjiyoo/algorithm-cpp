#include <iostream>
#include <algorithm>
#include <string>

int N, M;
char board[50][50];
char chess1[8][8];
char chess2[8][8];

void makeChess() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                chess1[i][j] = 'W';
                chess2[i][j] = 'B';
            }
            else {
                chess1[i][j] = 'B';
                chess2[i][j] = 'W';
            }
        }
    }
}

void input() {
    std::cin >> N >> M;
    
    std::string color;
    for (int i = 0; i < N; ++i) {
        std::cin >> color;
        for (int j = 0; j < M; ++j) {
            board[i][j] = color[j];
        }
    }
}


int compare(int& y, int& x) {
    
    int count1 = 0;
    int count2 = 0;
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i + y][j + x] != chess1[i][j]) {
                ++count1;
            }
            if (board[i + y][j + x] != chess2[i][j]) {
                ++count2;
            }
        }
    }
    
    return std::min(count1, count2);
}


int solve() {
    
    int min = 0x7fffffff;
    int R = 0;
    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            R = compare(i, j);
            if (R < min) {
                min = R;
            }
        }
    }
    
    return min;
}


int main (int argc, const char* argv []) {
    
    makeChess();
    input();
    std::printf("%d", solve());
    
    return 0;
}
