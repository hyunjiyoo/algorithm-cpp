#include <iostream>
#include <cmath>

int clockarr[16];
int result;

void init() {
    result = 999;
    int time;
    for (int i = 0; i < 16; ++i) {
        std::cin >> time;
        clockarr[i] = time;
    }
    
}

const int switcharr[10][6] = {
    { 0, 1, 2 , -1},
    { 3, 7, 9, 11, -1 },
    { 4, 10, 14, 15, -1 },
    { 0, 4, 5, 6, 7, -1 },
    { 6, 7, 8, 10, 12, -1 },
    { 0, 2, 14, 15, -1 },
    { 3, 14, 15, -1 },
    { 4, 5, 7, 14, 15, -1 },
    { 1, 2, 3, 4, 5, -1 },
    { 3, 4, 5, 9, 13, -1 }
};


// 스위치 누르기
void pushSwitch(int num, int count, int flag) {
    
    // 스위치 누르는 횟수
    for (int i = 0; i < count; ++i) {
        // 스위치눌렀을때 해당 스위치 번호에 따라 시간 변경.
        for (int j = 0; j < 6; ++j) {
            
            int idx = switcharr[num][j];
            
            if (idx == -1)
                break;
            
            clockarr[idx] += (3 * flag);
            
            if (clockarr[idx] == 0)
                clockarr[idx] = 12;
            if (clockarr[idx] == 15)
                clockarr[idx] = 3;
        }
    }
}


bool checkTime() {
    bool flag = true;
    for (int i = 0; i < 16; ++i) {
        if (clockarr[i] != 12) {
            flag = false;
            break;
        }
    }
    
    return flag;
}

void clocksync(int snum = 0, int clickcnt = 0) {
    
    if (snum >= 10)
        return;
    
    // 모두 12가 되면 전의 카운트와 비교해서 지금까지 누른 개수와 최종 최소값을 비교해서 갱신할 것임.
    if (checkTime()) {
        result = std::min(result, clickcnt);
        return;
    }
    
    
    // 0~9까지의 스위치 누르기 (k번)
    for (int k = 0; k < 4; ++k) {
        pushSwitch(snum, k, 1);
        clocksync(snum + 1, clickcnt + k);
        pushSwitch(snum, k, -1);
    }
    
    return;
}



int main(int argc, const char * argv[]) {
    int case_cnt;
    std::cin >> case_cnt;
    
    
    for (int i = 0; i < case_cnt; ++i) {
        init();
        clocksync();
        
        if (result == 999) {
            result = -1;
        }
        
        std::cout << result << std::endl;
    }
    
    return 0;
}

// 12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
