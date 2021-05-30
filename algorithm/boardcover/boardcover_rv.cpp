#include <iostream>


const int max_len = 20;
int height;
int width;
bool gameboard[max_len][max_len];
int w_cnt;
int L_cnt;
int tot_cnt;

enum : char {
    WHITE = '.',
    BLACK = '#'
};

void print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << gameboard[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void init() {
    
    w_cnt = 0;
    L_cnt = 0;
    tot_cnt = 0;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            gameboard[i][j] = true;
        }
    }
    
    std::string item;
    for (int i = 0; i < height; ++i) {
        std::cin >> item;
        for (int j = 0; j < width; ++j) {
            if (item[j] == WHITE) {
                gameboard[i][j] = false;
                w_cnt += 1;
            }
        }
    }
}

int offset[4][3][2] = {
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {0, 1}, {1, 0} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, -1}, {1, 0} }
};


bool changeL(int a, int b, int k, bool found) {
    
    bool able = true;
    for (int i = 0; i < 3; ++i) {
        
        int x = a + offset[k][i][0];
        int y = b + offset[k][i][1];
        
        if(gameboard[x][y] == found) {
            able = false;
            break;
        }

    }
    
    if(able) {
        for (int i = 0; i < 3; ++i) {
            
            int x = a + offset[k][i][0];
            int y = b + offset[k][i][1];
            
            gameboard[x][y] = found;
        }
    }
    return able;
}


bool pickBasis(int& x, int& y) {
    for (int i = 0; i < height - 1; ++i) {
        for (int j = 0; j < width; ++j) {
            if (gameboard[i][j])
                continue;
            
            x = i;
            y = j;
            
            return true;
        }
    }
    return false;
}

void play() {
    
    if (L_cnt * 3 >= w_cnt) {
        tot_cnt += 1;
        return;
    }
    
    int x;
    int y;
    if (pickBasis(x, y)) {
        for (int i = 0; i < 4; ++i) {
            bool flag = false;
            flag = changeL(x, y, i, true);
            
            if (flag) {
                L_cnt += 1;
                play();
                changeL(x, y, i, false);
                L_cnt -= 1;
            }
        }
    }
}


int main() {
    
    int case_cnt;
    std::cin >> case_cnt;
    
    for (int i = 0; i < case_cnt; ++i) {
        
        std::cin >> height >> width;
        init();
        play();
        
        std::cout << tot_cnt << std::endl;
    }
    
    return 0;
}
