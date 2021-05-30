#include <iostream>

const int std_max_cnt = 10;
int std_cnt;
int pair_cnt;
int tot_cnt;
bool friends[std_max_cnt][std_max_cnt];
bool selected[std_max_cnt];

void init() {
    tot_cnt = 0;
    
    for (int i = 0; i < std_cnt; ++i) {
        selected[i] = false;
        for (int j = 0; j < std_cnt; ++j) {
            friends[i][j] = false;
        }
    }
    
    int a; int b;
    for (int i = 0; i < pair_cnt; ++i) {
        std::cin >> a >> b;
        
        friends[a][b] = true;
        friends[b][a] = true;
    }
}


int selectedStd() {
    int std = -1;
    for (int i = 0; i < std_cnt; ++i) {
        if (selected[i] == false) {
            std = i;
        }
    }
    return std;
}

void pairFriend(bool* selected) {
    if (selectedStd() == -1) {
        tot_cnt += 1;
        return;
    }
    
    int std = selectedStd();
    selected[std] = true;
    
    for (int i = 0; i < std_cnt; ++i) {
        if (selected[i] || !friends[std][i])
            continue;
        
        int std_pair = i;
        selected[std_pair] = true;
        
        pairFriend(selected);
        
        selected[std_pair] = false;
    }
    selected[std] = false;
    
}


int main() {
    int case_cnt;
    
    std::cin >> case_cnt;
    for (int i = 0; i < case_cnt; ++i) {
        std::cin >> std_cnt >> pair_cnt;
        
        init();
        pairFriend(selected);
        std::printf("%d\n", tot_cnt);
    }
    
    return 0;
}
