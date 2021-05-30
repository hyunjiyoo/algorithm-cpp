#include <iostream>

int H;
int W;
int board[20][20];
int w_cnt;
int l_cnt;
int tot_cnt;

enum : char {
    WHITE = '.',
    BLACK = '#'
};


void init() {
    w_cnt = 0;
    l_cnt = 0;
    tot_cnt = 0;
    
    std::string item;
    for (int i = 0; i < H; ++i) {
        
        std::cin >> item;
        
        for (int j = 0; j < W; ++j) {
            board[i][j] = true;
            
            if (item[j] == WHITE) {
                board[i][j] = false;
                w_cnt += 1;
            }
        }
    }
}


int typearr[4][3][2] = {
    { {0, 0}, {1, 0}, {1, 1}},
    { {0, 0}, {0, 1}, {1, 0}},
    { {0, 0}, {0, 1}, {1, 1}},
    { {0, 0}, {1, 0}, {1, -1}}
};

bool findL(int x, int y, int type, bool flag) {
    
    bool able = true;
    for (int i = 0; i < 3; ++i) {
        
        int offx = x + typearr[type][i][0];
        int offy = y + typearr[type][i][1];
        
        if (board[offx][offy] == flag) {
            able = false;
            break;
        }
    }
    
    if (able) {
        for (int i = 0; i < 3; ++i) {
            
            int offx = x + typearr[type][i][0];
            int offy = y + typearr[type][i][1];
            
            board[offx][offy] = flag;
        }
    }
    
    return able;
}

// 기준을 선택해야함!! x와 y를 레퍼런스 변수로 받는다!!
bool selectBasis(int& x, int& y) {
    
    for (int i = 0; i < H - 1; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!board[i][j]) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}


void solve() {
 
    // l의 개수 * 3 = 흰색개수은 모두 채웠다는 의미
    if (l_cnt * 3 >= w_cnt) {
        tot_cnt += 1;
        return;
    }
    
    int x;
    int y;
    // selectBasis()가 true가 아니라는 것은 더이상 뽑을 기준이 없다는 것. (탐색완료)
    if (selectBasis(x, y)) {
        for (int k = 0; k < 4; ++k) {
            if (findL(x, y, k, true)) {
                l_cnt += 1;
                solve();
                findL(x, y, k, false);
                l_cnt -= 1;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int C;
    std::cin >> C;
      
    for (int i = 0; i < C; ++i) {
        std::cin >> H >> W;
        
        init();
        solve();
        
        std::printf("%d\n", tot_cnt);
    }
    
    return 0;
}
