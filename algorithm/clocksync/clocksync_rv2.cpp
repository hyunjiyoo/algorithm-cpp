#include <iostream>

int ret;
int clocks[16];

int swtch[10][6] = {
    { 0, 1, 2, -1 },
    { 3, 7, 9, 11, -1 },
    { 4, 10, 14, 15, -1 },
    { 0, 4, 5, 6, 7,  -1 },
    { 6, 7, 8, 10, 12, -1 },
    { 0, 2, 14, 15, -1 },
    { 3, 14, 15, -1 },
    { 4, 5, 7, 14, 15, -1 },
    { 1, 2, 3, 4, 5, -1 },
    { 3, 4, 5, 9, 13, -1 }
};

void init() {
    ret = 9999;
    
    for (int i = 0; i < 16; ++i) {
        std::cin >> clocks[i];
    }
}

void push(int swt_num, int count, int flag) {
    
    for (int i = 0; i < 6; ++i) {
        if (swtch[swt_num][i] == -1)
            break;
        
        int idx = swtch[swt_num][i];
        
        for (int j = 0; j < count; ++j) {
            clocks[idx] += 3 * flag;
            
            if (clocks[idx] == 15)
                clocks[idx] = 3;
            
//            if (clocks[idx] == 0)
//                clocks[idx] = 12;
        }
    }
}

// 시계가 하나라도 12를 가리키지 않으면 return false;
bool chkTime() {
    bool flag = true;
    for (int i = 0; i < 16; ++i) {
        if (clocks[i] != 12) {
            flag = false;
            break;
        }
    }
    return flag;
}


void solve(int swt_num = 0, int count = 0) {
    
    // 스위치넘버가 10이 되면 리턴
    if (swt_num == 10) return;
    
    for (int i = 0; i < 4; ++i) {
        // 스위치넘버와 클릭횟수를 넘기면서 시간 3 증가
        push(swt_num, i, 1);
        
        // 누르고나서 시간체크 맞으면 최솟값 갱신
        if (chkTime()) {
            ret = std::min(ret, count + i);
            return;
        }
        
        solve(swt_num + 1, count + i);
        
        push(swt_num, i, 1);
        
        // 스위치넘버와 클릭횟수를 넘기면서 시간 3 감소
        push(swt_num, i, -1);
        
    }
}


int main(int argc, const char * argv[]) {
    
    int C;
    std::cin >> C;
    for (int i = 0; i < C; ++i) {
        
        init();
        solve();
        
        if (ret == 9999)
            ret = -1;
        
        std::printf("%d\n", ret);
    }
    
    return 0;
}
