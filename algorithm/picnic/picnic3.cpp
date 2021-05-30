#include <iostream>

int case_cnt;
int std_cnt;
int pair_cnt;
int tot_cnt;
const int std_max_cnt = 10;
bool visit[std_max_cnt];
bool isFriend[std_max_cnt][std_max_cnt];
int friend_list[std_max_cnt-1][std_max_cnt];


int selectBasis() {
    int basis = -1;
    for (int i = 0; i < std_cnt; ++i) {
        if (!visit[i]) {
            basis = i;
            break;
        }
    }
    return basis;
}


void setFriend() {
    for (int i = 0; i < std_cnt - 1; ++i) {
        for (int j = 0; j < std_cnt; ++j) {
            friend_list[i][j] = 0;
        }
    }

    for (int i = 0; i < std_cnt - 1; ++i) {
        int idx = 0;
        for (int j = 0; j < std_cnt; ++j) {
            if(isFriend[i][j] && j >= i) {
                friend_list[i][idx++] = j;
            }
        }
    }
}

int step = 0;

void combination() {
    
    if (step * 2 >= std_cnt) {
        tot_cnt += 1;
        
        return;
    }
    
    int basis = selectBasis();
    visit[basis] = true;
    
    for (int i = 0; i < std_cnt; ++i) {
        
        int basis_pair = friend_list[basis][i];
        
        if(basis_pair == 0 || visit[basis_pair])
            continue;
        
        visit[basis_pair] = true;
        
        step += 1;
        combination();
        step -= 1;
        
        visit[basis_pair] = false;
    }
    visit[basis] = false;
}
                        

void init() {
    tot_cnt = 0;
    step = 0;
    
    std::cin >> std_cnt >> pair_cnt;
    
    for (int i = 0; i < std_cnt; ++i) {
        visit[i] = false;
    }
    
    
    for (int i = 0; i < std_cnt; ++i) {
        for (int j = 0; j < std_cnt; ++j) {
            isFriend[i][j] = false;
        }
    }
    
    int left; int right;
    for (int i = 0; i < pair_cnt; ++i) {
        std::cin >> left >> right;
        
        isFriend[left][right] = true;
        isFriend[right][left] = true;
    }
}



int main() {
    std::cin >> case_cnt;
    
    for (int i = 0; i < case_cnt; ++i) {
        init();
        setFriend();
        combination();
        
        std::cout << tot_cnt << std::endl;
    }
    
    
    return 0;
}
