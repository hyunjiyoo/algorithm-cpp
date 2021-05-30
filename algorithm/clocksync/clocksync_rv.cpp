#include <iostream>

int result;
int timearr[16];

void init() {
    result = 999;
    for (int i = 0; i < 16; ++i)
        std::scanf("%d", timearr + i);
}


const int switchlist[10][6] = {
    { 0, 1, 2 , -1 },
    { 3, 7, 9, 11 , -1 },
    { 4, 10, 14, 15 , -1 },
    { 0, 4, 5, 6, 7, -1 },
    { 6, 7, 8, 10, 12, -1 },
    { 0, 2, 14, 15, -1 },
    { 3, 14, 15 , -1 },
    { 4, 5, 7, 14, 15, -1 },
    { 1, 2, 3, 4, 5, -1 },
    { 3, 4, 5, 9, 13, -1 }
};


void clickSwitch(int swt_num, int count, int flag) {
    
    
    for (int j = 0; j < count; ++j) {
        
        for (int i = 0; i < 6; ++i) {
            
            int idx = switchlist[swt_num][i];
            
            if (idx == -1) {
                break;
            }
            
            timearr[idx] += 3 * flag;
            
            // 3 - 3  = 0 / 12 + 3 = 15
            if (timearr[idx] == 0 || timearr[idx] > 12) {
                timearr[idx] -= 12 * flag;
            }
        }
    }
    
    return;
}


bool timecheck() {
    
    bool flag = true;
    for (int i = 0; i < 16; ++i) {
        if (timearr[i] != 12) {
            flag = false;
            break;
        }
    }
    
    return flag;
}


void print() {
    for (int i = 0; i < 16; ++i) {
        std::cout << timearr[i] << ' ';
    }
    std::cout << std::endl;
}


//void clocksync(int swt_num = 0, int count = 0) {
//    if (timecheck()) {
//        result = std::min(result, count);
//        return;
//    }
//
//    if (swt_num >= 10)
//        return;
//
//    for (int i = 0; i < 4; ++i) {
//        clickSwitch(swt_num, i, 1);
//        clocksync(swt_num + 1, count + i);
//        clickSwitch(swt_num, i, -1);
//    }
//
//}

void clocksync(int swt_num = 0, int count = 0) {
    if (swt_num >= 10 || count >= result) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        clickSwitch(swt_num, i, 1);

        if (timecheck())
            result = std::min(result, count + i);
        else
            clocksync(swt_num + 1, count + i);

        clickSwitch(swt_num, i, -1);
    }
}



int main(int argc, const char * argv[]) {
    int case_cnt;
    std::scanf("%d", &case_cnt);
    
    for (int i = 0; i < case_cnt; ++i) {
        
        init();
        clocksync();
        
        if (result == 999)
            result = -1;
        
        std::printf("%d\n", result);
    }
    
    return 0;
}
