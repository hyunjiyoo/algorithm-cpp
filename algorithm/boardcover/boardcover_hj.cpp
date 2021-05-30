#include <iostream>

int board[20][20];
int c, height, width;

const int coverType[4][3][2] = {
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

void print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool set(int y, int x, int type, int delta) {
    bool ok = true;
    
    for (int i = 0; i < 3; ++i) {
        
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        
        if (ny < 0 || ny >= height || nx < 0 || nx >= width)
            ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    
    return ok;
}

bool pickBasis(int& y, int& x) {
    for (int i = 0; i < height - 1; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j])
                continue;
            
            y = i;
            x = j;
            
            return true;
        }
    }
    return false;
}

int cover() {
    int y, x;
    if (!pickBasis(y, x)) {
        print();
        return 1;
    }

    int ret = 0;
    for (int type = 0; type < 4; ++type) {
    
        if (set(y, x, type, 1)) {
            ret += cover();
        }
        
        set(y, x, type, -1);
        std::cout << "----------" << std::endl;
        print();
        
    }
    return ret;
}

void init() {
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            board[i][j] = 1;
        }
    }
    
    std::cin >> height >> width;
    
    for(int j = 0; j < height; ++j) {
        std::string line;
        std::cin >> line;
        for (int k = 0; k < width; ++k) {
            if (line[k] == '.')
                board[j][k] = 0;
        }
    }
}
int main() {
    std::cin >> c;
    for(int i = 0; i < c; ++i) {
        init();
        int cnt = cover();
        std::cout << cnt << std::endl;
    }
    
    return 0;
}
