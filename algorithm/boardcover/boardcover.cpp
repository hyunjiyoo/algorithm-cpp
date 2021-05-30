#include <iostream>

const int max_len = 20;
int height;
int width;
bool gameboard[max_len][max_len];
int w_cnt;
int L_cnt;
int tot_cnt;

enum : char {
    EMPTY = '.',
    WALL = '#'
};


void init() {
    
    tot_cnt = 0;
    L_cnt = 0;
    w_cnt = 0;
    
    for (int i = 0; i < max_len; ++i) {
        for (int j = 0; j < max_len; ++j) {
            gameboard[i][j] = true;
        }
    }
    
    std::string item;
    for (int i = 0; i < height; ++i) {
        std::cin >> item;
        for (int j = 0; j < width; ++j) {
            if(item[j] == EMPTY) {
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
    { {0, 0}, {1, 0}, {1, -1} },
};

// flag == true => select
// flag == flase => unselect
bool change(int a, int b, int k, bool flag) {
    auto blockoff = offset[k];
    
    bool able = true;
    
    for (int i = 0; i < 3; ++i) {
        
        int xoff = blockoff[i][0];
        int yoff = blockoff[i][1];
        
        if (gameboard[a + xoff][b + yoff] == flag) {
            able = false;
            break;
        }
    }
    
    if (able) {
        for (int i = 0; i < 3; ++i) {
        
            int xoff = blockoff[i][0];
            int yoff = blockoff[i][1];
            
            gameboard[a + xoff][b + yoff] = flag;
        }
    }
    
    return able;
}

bool selectL(int a, int b, int k) {
    auto blockoff = offset[k];
    
    bool able = true;
    
    for (int i = 0; i < 3; ++i) {
        
        int xoff = blockoff[i][0];
        int yoff = blockoff[i][1];
        
        if (gameboard[a + xoff][b + yoff]) {
            able = false;
            break;
        }
    }
    
    if (able) {
        for (int i = 0; i < 3; ++i) {
        
            int xoff = blockoff[i][0];
            int yoff = blockoff[i][1];
            
            gameboard[a + xoff][b + yoff] = true;
        }
    }
    
    return able;
    
    
    
    switch (k) {
        case 0: // ㄴ
            if (!gameboard[a][b] && !gameboard[a+1][b] && !gameboard[a+1][b+1]) {
                gameboard[a][b] = true;
                gameboard[a+1][b] = true;
                gameboard[a+1][b+1] = true;
                return true;
            } else {
                return false;
            }
        
        case 1: // r
            if (!gameboard[a][b] && !gameboard[a][b+1] && !gameboard[a+1][b]) {
                gameboard[a][b] = true;
                gameboard[a][b+1] = true;
                gameboard[a+1][b] = true;
                return true;
            } else {
                return false;
            }
        
        case 2: // ㄱ
            if (!gameboard[a][b] && !gameboard[a][b+1] && !gameboard[a+1][b+1]) {
                gameboard[a][b] = true;
                gameboard[a][b+1] = true;
                gameboard[a+1][b+1] = true;
                return true;
            } else {
                return false;
            }
            
        case 3: // ㅓ
            if (!gameboard[a][b] && !gameboard[a+1][b] && !gameboard[a+1][b-1]) {
                gameboard[a][b] = true;
                gameboard[a+1][b] = true;
                gameboard[a+1][b-1] = true;
                return true;
            } else {
                return false;
            }
        default:
            return false;
    }
}


void unselectL(int a, int b, int k) {
    
    switch (k) {
        case 0:
            if (gameboard[a][b] && gameboard[a+1][b] && gameboard[a+1][b+1]) {
                gameboard[a][b] = false;
                gameboard[a+1][b] = false;
                gameboard[a+1][b+1] = false;
            }
        
        case 1:
            if (gameboard[a][b] && gameboard[a][b+1] && gameboard[a+1][b]) {
                gameboard[a][b] = false;
                gameboard[a][b+1] = false;
                gameboard[a+1][b] = false;
                
            }
        
        case 2:
            if (gameboard[a][b] && gameboard[a][b+1] && gameboard[a+1][b+1]) {
                gameboard[a][b] = false;
                gameboard[a][b+1] = false;
                gameboard[a+1][b+1] = false;
            }
            
        case 3:
            if (gameboard[a][b] && gameboard[a+1][b] && gameboard[a+1][b-1]) {
                gameboard[a][b] = false;
                gameboard[a+1][b] = false;
                gameboard[a+1][b-1] = false;
            }
        
    }
}

bool selectBasis(int& x, int& y) {
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
    
    int x, y;
    if(selectBasis(x, y)) {
        
        bool flag = false;
        for (int k = 0; k < 4; ++k) {
            flag = selectL(x, y, k);
            
            if(flag) {
                L_cnt += 1;
                play();
                unselectL(x, y, k);
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
