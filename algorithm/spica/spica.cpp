#include <iostream>

int x, y, ret;
int count[13];
int star[12][2];

void input() {
    for (int i = 1; i <= 12; ++i) {
        std::scanf("%d %d", &x, &y);
        star[i - 1][0] = x;
        star[i - 1][1] = y;
        ++count[x];
        ++count[y];
    }
}


void solve() {
    
    // 선분이 3개인 점 구하기
    int j = 0;
    int three_cnt_dot[4];
    for (int i = 1; i <= 12; ++i) {
        if (count[i] == 3) {
            three_cnt_dot[j] = i;
            ++j;
        }
    }
    
    // 선분이 3개인 점들에 연결되어 있는 점 구하기
    // 연결되어 있는 점들의 선분합이 6이 되면 리턴
    int k;
    int sum;
    int connect_dot[4][3];
    for (int i = 0; i < 4; ++i) {
        k = sum = 0;
        for (int j = 0; j < 12; ++j) {
            if (star[j][0] == three_cnt_dot[i]) {
                connect_dot[i][k] = star[j][1];
                ++k;
            }
            
            if (star[j][1] == three_cnt_dot[i]) {
                connect_dot[i][k] = star[j][0];
                ++k;
            }
        }
        
        for (int j = 0; j < 3; ++j)
            sum += count[connect_dot[i][j]];
        
        if (sum == 6) {
            ret = three_cnt_dot[i];
            return;
        }
    }
}


int main (int argc, const char* argv []) {
    
    input();
    solve();
    std::printf("%d", ret);
    
    return 0;
}
