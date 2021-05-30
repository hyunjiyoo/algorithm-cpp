#include <iostream>
#include <algorithm>

int64_t N;
int M;
int64_t BUS[500'000][4];
int64_t* PBUS[500'000];
bool POSSIBLE[500'000];

void init() {
    for (int i = 0; i < 500'000; ++i) {
        BUS[i][0] = 0;
        BUS[i][1] = 0;
        BUS[i][2] = 0;
        BUS[i][3] = 0;
        PBUS[i] = BUS[i];
        POSSIBLE[i] = true;
    }
}


void input() {
    std::scanf("%lld", &N);
    std::scanf("%d", &M);
    
    for (int i = 0; i < M; ++i) {
        BUS[i][2] = i;
        std::scanf("%lld %lld", &BUS[i][0], &BUS[i][1]);
        
        if (BUS[i][1] > BUS[i][0])
            BUS[i][3] = BUS[i][1] - BUS[i][0];
        else
            BUS[i][3] = (N - BUS[i][0]) + BUS[i][1];
    }
}


void sort() {
    std::sort(PBUS, PBUS + M, [](auto l, auto r) {
        return l[3] > r[3];
    });
}


void solve() {
    auto& BUS = PBUS;
    
    int64_t basis_L = 0;
    int64_t basis_R = 0;
    int64_t basis_num = 0;
    
    int64_t comp_L = 0;
    int64_t comp_R = 0;
    int64_t comp_num = 0;
    
    for (int i = 0; i < M - 1; ++i) {
        basis_L = BUS[i][0];
        basis_R = BUS[i][1];
        basis_num = BUS[i][2];
        
        if (!POSSIBLE[basis_num]) {
            continue;
        }
        
        for (int j = i + 1; j < M; ++j) {
            comp_L = BUS[j][0];
            comp_R = BUS[j][1];
            comp_num = BUS[j][2];
            
            if (BUS[i][3] == BUS[j][3] || !POSSIBLE[comp_num])
                continue;
            
            if (basis_L < basis_R) {
                if (comp_L < comp_R) {
                    if ((comp_L >= basis_L) && (comp_R <= basis_R))
                        POSSIBLE[comp_num] = false;
                }
                else {
                    if (((comp_L >= basis_L) && (comp_R < N)) || ((comp_L >= 0) && (comp_R <= basis_R)))
                        POSSIBLE[comp_num] = false;
                }
            }
            else {
                if (comp_L < comp_R) {
                    if (((comp_L >= basis_L) && (comp_R < N)) || ((comp_L >= 0) && (comp_R <= basis_R)))
                        POSSIBLE[comp_num] = false;
                }
                else {
                    if ((comp_L >= basis_L) && (comp_R <= basis_R))
                        POSSIBLE[comp_num] = false;
                }
            }
        }
    }
}


void result() {
    int last_idx = -1;
    for (int i = M - 1; i >= 0; --i) {
        if (POSSIBLE[i]) {
            last_idx = i;
            break;
        }
    }

    for (int i = 0; i < last_idx; ++i)
        if (POSSIBLE[i])
            std::printf("%d ", i + 1);

    if (last_idx != -1)
        std::printf("%d", last_idx + 1);
}


int main (int argc, const char * argv []) {
    
    init();
    input();
    sort();
    solve();
    result();
    
    return 0;
}
